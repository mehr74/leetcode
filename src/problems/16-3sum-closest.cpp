class Solution {
public:
    Solution () {
        std::ios::sync_with_stdio(false);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int currSum;
        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < nums.size() - 2; idx++) {
            int lo = idx + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                currSum = nums[lo] + nums[hi] + nums[idx];
                if (abs(currSum - target) < abs(diff))
                    diff = target - currSum;
                if (currSum < target)
                    lo++;
                else if (currSum > target)
                    hi--;
                else 
                    return target;
                
            }
        }
        return target - diff;
        
    }
};
