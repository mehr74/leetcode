class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int> st; 
      unordered_map<int, int> mp;

      for (auto &num2 : nums2) {
        while (!st.empty() && st.top() < num2) {
          mp[st.top()] = num2;
          st.pop();
        }
        st.push(num2);
      }

      vector<int> result(nums1.size(), -1);
      for (int i = 0; i < nums1.size(); i++) {
        if (mp.find(nums1[i]) != mp.end()) {
          result[i] = mp[nums1[i]];
        }
      }
      return result;
    }

    Solution() {
        std::ios::sync_with_stdio(false);
    }
};
