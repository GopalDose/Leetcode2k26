class Solution {
public:

    bool isvalid(int q, int n, vector<int>& quantities){
        int count = 0;
        for(auto i : quantities){
            count += i/q;
            count += i%q ? 1 : 0;
        }
        return count <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int e = *max_element(quantities.begin(), quantities.end());
        int s = 1;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(isvalid(mid, n, quantities)) e =mid-1;
            else s = mid+1;
        }
        return s;
    }
};