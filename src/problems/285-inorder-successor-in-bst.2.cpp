class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        
        while (root != nullptr) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
        
    }
};
