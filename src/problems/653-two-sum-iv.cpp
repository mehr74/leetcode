class Solution {
  public:
    bool findTarget(TreeNode* root, int k) {
      stack<TreeNode*> nodes;
      unordered_set<int> ss;
      nodes.push(root);
      while (!nodes.empty()) {
        TreeNode* node = nodes.top();
        if (node == nullptr)
          continue;
        if (ss.find(node->val) != ss.end())
          return true;
        ss.insert(k - node->val);
        nodes.push(node->left);
        nodes.push(node->right);
      }
      return false;
    }
};
