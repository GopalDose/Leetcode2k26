class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            int start = i, end = i;

            while (start >= 0 && end < s.length() && s[start] == s[end]) {
                start--;
                end++;
            }

            int len = end - start - 1;
            if (len > ans.length()) {
                ans = s.substr(start + 1, len);
            }

            start = i, end = i + 1;
            while (start >= 0 && end < s.length() && s[start] == s[end]) {
                start--;
                end++;
            }

            len = end - start - 1;
            if (len > ans.length()) {
                ans = s.substr(start + 1, len);
            }
        }

        return ans;
    }
};