class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            int rem = x%10;
            x /= 10;
            if(ans > INT_MAX/10) return 0;
            if(ans < INT_MIN/10) return 0;
            ans = ans*10+rem;
        }
        return ans;
    }
};