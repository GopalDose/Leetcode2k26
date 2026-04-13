class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size()-1];

        int prefix = 0;
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i]) break; prefix++;
        }
        return str1.substr(0, prefix);
    }
};