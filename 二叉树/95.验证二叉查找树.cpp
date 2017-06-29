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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    void inorder(TreeNode* root, vector<int> &res)
    {
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(!root)
            return true;
        vector<int> res;
        inorder(root, res);
        for(int i = 0; i < res.size() - 1; i++)
        {
            if(res[i + 1] <= res[i])
                return false;
        }
        return true;
    }
};
