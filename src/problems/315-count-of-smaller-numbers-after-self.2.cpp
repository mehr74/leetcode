class Solution {
public:
    Solution (){
        std::ios::sync_with_stdio(false);
    }
    void insert(int val, int start, int end, int idx) {
        if (vals.find(idx) == vals.end())
            vals.insert(make_pair(idx, 0));
        
        if (val < start | val > end)
            return;
        
        if (start == end) {
            vals[idx]++;
            return;
        }
        
        while (start != end) {
            int mid = (start + end) / 2;
            vals[idx]++;
            if (val > mid) {
                idx = idx * 2 + 1;
                start = mid + 1;
            } else {
                idx = idx * 2;
                end = mid;
            }
        }
        vals[idx]++;
    }
    
    int count(int start, int end, int left, int right, int idx) {
        if (end < left || start > right)
            return 0;
        
        if (start <= left && end >= right)
            return vals[idx];
        
        int mid = (right + left) / 2;
        int leftCnt = count(start, end, left, mid, idx * 2);
        int rightCnt = count(start, end, mid + 1, right, idx * 2 + 1);
        return rightCnt + leftCnt;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> countVec(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            countVec[i] = count(0, nums[i] + 10000, 0, 20001, 1);
            insert(nums[i] + 10001, 0, 20001, 1);
        }
        return countVec;
    }
    
    map<int, int> vals;
};
