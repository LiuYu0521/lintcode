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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    void helper(TreeNode* root, vector<int> &res)
    {
        if(!root)
            return;
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root)
            return res;
        helper(root, res);
        return res;
    }
};
