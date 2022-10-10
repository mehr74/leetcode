class Solution {
  public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      stack<TreeNode *> st;
      TreeNode* currNode = root;
      bool returnNextNode = false;
      while (currNode != nullptr || !st.empty()) {
        while (currNode != nullptr) {
          st.push(currNode);
          currNode = currNode->left;
        }
        currNode = st.top();
        st.pop();
        if (returnNextNode)
          return currNode;
        if (currNode == p)
          returnNextNode = true;
        currNode = currNode->right;
      }
      return nullptr;

    }
};
