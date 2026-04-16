class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;

        // store value -> indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;
        int n = nums.size();

        for (int q : queries) {
            vector<int>& ind = mp[nums[q]];
            int size = ind.size();

            if (size == 1) {
                res.push_back(-1);
                continue;
            }

            int pos = binarySearch(ind, q);

            int left = (pos - 1 + size) % size;
            int right = (pos + 1) % size;

            int dist1 = abs(ind[pos] - ind[left]);
            int dist2 = abs(ind[pos] - ind[right]);

            // circular distance
            dist1 = min(dist1, n - dist1);
            dist2 = min(dist2, n - dist2);

            res.push_back(min(dist1, dist2));
        }

        return res;
    }
};