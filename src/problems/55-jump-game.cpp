class Solution {
  public:
  bool canJump(vector<int>& nums) {
    stack<int> st;
    vector<int> seen(nums.size(), 0);

    st.push(0);
    while(!st.empty()) {
      int pos = st.top();
      st.pop();
      seen[pos] = 1;

      int nextPos = pos+1;
      while (nextPos <= pos + nums[pos] && nextPos < nums.size()) {
        if (nextPos == nums.size() - 1)
          return true;
        if (seen[nextPos] == 0)
          st.push(nextPos);
        nextPos++;
      }
    }
    return (seen[nums.size() - 1] == 1);
  }
};
