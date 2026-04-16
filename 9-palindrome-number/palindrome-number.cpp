class Solution {
public:
    bool isPalindrome(int x) {
        long ans = 0;

        int t = x;

        if(x < 0) return false;

        while(t){
            ans = ans*10+(t%10);
            t /= 10;
        }
        return ans == x;
    }
};