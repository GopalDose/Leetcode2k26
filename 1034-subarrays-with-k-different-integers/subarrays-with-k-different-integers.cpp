class Solution {
public:
    int sliding(vector<int>& nums, int k){
        int start = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;

            while(mp.size() > k){
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) mp.erase(nums[start]);
                start++;
            }
            count += i - start+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding (nums,k) - sliding (nums,k-1);
    }
};