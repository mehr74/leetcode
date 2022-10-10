class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int threeSumSmallerCnt = 0;
        int sz = nums.size();
        int sum;
        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < sz - 2; idx++) {
            int lo = idx + 1;
            int hi = sz - 1;
            
            while (lo < hi) {
                sum = nums[idx] + nums[lo] + nums[hi];
                if (sum < target) {
                    threeSumSmallerCnt += (hi - lo);
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        return threeSumSmallerCnt;
    }
};
