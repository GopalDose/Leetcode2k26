class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.length(), 0);
        int j = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[j])
                lps[i] = ++j;
            else if (j > 0) {
                j = lps[j - 1];
                i--;
            }
        }
        return s.substr(0, j);
    }
};