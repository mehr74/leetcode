class MyCalendarThree {
  public:
    MyCalendarThree() {
      maxHeight = 0;
    }

    int book(int start, int end) {
      int startHeight = 1;
      int endHeight = -1;
      for (auto& entry : mp) {
        if (entry.first < start) {
          startHeight = entry.second + 1;
        } else if (entry.first >= start && entry.first < end) {
          entry.second++;
          endHeight = entry.second - 1;
          maxHeight = max(entry.second, maxHeight);
        } else if (entry.first == end) {
          endHeight = entry.second;
        } else {
          break;
        }
      }
      endHeight = (endHeight == -1) ? startHeight - 1 : endHeight;

      if (mp.find(start) == mp.end()) {
        mp.insert(make_pair(start, startHeight));
        maxHeight = max(maxHeight, startHeight);
      }
      if (mp.find(end) == mp.end())
        mp.insert(make_pair(end, endHeight));

      return maxHeight;
    }

    map<int, int> mp;
    int maxHeight;
}; 
