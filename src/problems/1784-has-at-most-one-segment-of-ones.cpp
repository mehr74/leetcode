class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
    }
    bool checkOnesSegment(string s) {
        char lastChar = '0';
        int oneSegmentCnt = 0;
        for (const auto& ch: s) {
            if (lastChar != '1' && ch == '1' && oneSegmentCnt == 0) {
                oneSegmentCnt++;
            }
            else if (lastChar != '1' && ch == '1' && oneSegmentCnt > 0) {
                return false;
            }
            lastChar = ch;
        }
        return true;
    }
};
