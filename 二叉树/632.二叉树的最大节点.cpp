class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* max(TreeNode* a, TreeNode* b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        return a->val > b->val ? a : b;
    }
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        if(!root)
            return root;
        TreeNode* left = maxNode(root->left);
        TreeNode* right = maxNode(root->right);
        return max(root, max(left, right));
    }
};
