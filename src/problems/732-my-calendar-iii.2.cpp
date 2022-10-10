class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int currHeight = 0;
        int maxHeight = 0;
        for (auto& entry : mp) {
            currHeight += entry.second;
            maxHeight = max(maxHeight, currHeight);
        }
        return maxHeight;
    }
    
    map<int, int> mp;
};
