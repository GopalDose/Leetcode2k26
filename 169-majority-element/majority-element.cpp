class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i : nums) mp[i]++;
        int ans = 0;
        for(auto i : mp){
            if(i.second > (n/2)) ans = i.first;
        }
        return ans;
    }
};