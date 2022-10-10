class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
    }
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq ('Z' - 'A' + 1, 0);
        for (auto& task : tasks) {
            freq[task - 'A']++;
        }
        
        int maxFreq = INT_MIN;
        int maxFreqCnt = 0;
        
        for (auto& fq : freq) {
            if (maxFreq < fq) {
                maxFreq = fq;
                maxFreqCnt = 1;
            } else if (maxFreq == fq) {
                maxFreqCnt++;
            }
        }
        
        return max(int(tasks.size()), (maxFreq - 1) * (n + 1) + maxFreqCnt);
    }
};
