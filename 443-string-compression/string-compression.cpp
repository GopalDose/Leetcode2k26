class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1)
            return 1;
        int count = 1;
        int start = 0;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1])
                count++;
            else {
                chars[start++] = chars[i - 1];
                if (count > 1)
                    for (const char c : to_string(count)) {
                    chars[start++] = c;
                }
                count = 1;
            }
        }
        chars[start++] = chars[chars.size()-1];
        if (count > 1)
            for (const char c : to_string(count)) {
                    chars[start++] = c;
                }
        return start;
    }
};