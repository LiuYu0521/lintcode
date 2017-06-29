/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the new root
     */
    void helper(TreeNode* node, int &sum)
    {
        if(!node)
            return;
        helper(node->right, sum);
        node->val += sum;
        sum = node->val;
        helper(node->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        // Write your code here
        int sum = 0;
        helper(root, sum);
        return root;
    }
};
