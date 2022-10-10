class Solution {
public:
    int amountPerDay(int start, int end, int left, int right, int idx) {
        if (remain.find(idx) == remain.end())
            remain.insert(make_pair(idx, right - left));
        
        if (remain[idx] == 0)
            return 0;
        
        if (start >= right || end <= left) {
            return 0;
        } else if (start <= left && end >= right) {
            int ret = remain[idx];
            remain[idx] = 0;
            return ret;
        } else {
            int mid = (left + right) / 2;
            int remainLeft = amountPerDay(start, end, left, mid, idx * 2);
            int remainRight = amountPerDay(start, end, mid, right, idx * 2 + 1);
            remain[idx] -= (remainLeft + remainRight);
            return remainLeft + remainRight;
        }
    }
    
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> paintPerDay(paint.size());
        for (int i = 0; i < paint.size(); i++) {
            paintPerDay[i] = amountPerDay(paint[i][0], paint[i][1], 0, 100000, 1);
        }
        return paintPerDay;
    }
    map<int, int> remain;
    map<int, int> lazy;
};
