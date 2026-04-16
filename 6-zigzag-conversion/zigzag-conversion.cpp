class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        if(numRows == 1) return s;

        int row = 0;
        bool as = true;
        for(auto i : s){
            rows[row] += i;
            if(row == 0) as = true;
            if(row == numRows-1) as = false;
            row += as ? 1 : -1;
        }

        string ans = "";
        for(auto i : rows){
            ans += i;
        }
        return ans;
    }
};