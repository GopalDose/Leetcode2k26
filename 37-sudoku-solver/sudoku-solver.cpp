class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++)
            if (board[i][col] == ch)
                return false;

        for (int i = 0; i < 9; i++)
            if (board[row][i] == ch)
                return false;

        int startR = row - row % 3;
        int startC = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startR + i][startC + j] == ch)
                    return false;
            }
        }
        return true;
    }

    bool solveS(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        if (col == 9) return solveS(board, row + 1, 0);

        if (board[row][col] != '.')
            return solveS(board, row, col + 1);
        for (char i = '1'; i <= '9'; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = i;
                if (solveS(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { solveS(board, 0, 0); }
};