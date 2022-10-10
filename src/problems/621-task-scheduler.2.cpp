class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq ('Z' - 'A' + 1, 0);
        for (auto& task : tasks) {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int maxFreq = freq[0];
        int idleTime = (freq[0] - 1) * n;
        for (int i = 1; i < freq.size() && idleTime > 0; i++) {
            idleTime -= min(maxFreq - 1, freq[i]);
        }
        idleTime = max(0, idleTime);
        return idleTime + tasks.size();
    }
};
