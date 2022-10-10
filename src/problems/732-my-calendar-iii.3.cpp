class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    void update(int start, int end, int left, int right, int idx) {
        if (start > right || end < left)
            return;
        if (start <= left && end >= right) {
            lazy[idx]++;
            val[idx]++;
        } else {
            int mid = (right + left) / 2;
            update(start, end, left, mid, idx * 2);
            update(start, end, mid + 1, right, idx * 2 + 1);
            val[idx] = lazy[idx] + max(val[2 * idx], val[2 * idx + 1]);
        }
    }
    int book(int start, int end) {
        update(start, end - 1, 1, 1000000010, 1);
        return val[1];
    }
    
    unordered_map<int, int> val;
    unordered_map<int, int> lazy;
};
