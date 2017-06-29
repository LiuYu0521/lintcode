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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> res;
        if(root)
            dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode* root, string out, vector<string> &res)
    {
        out = out + to_string(root->val);
        if(!root->left && !root->right)
            res.push_back(out);
        else
        {
            if(root->left)
                dfs(root->left, out + "->", res);
            if(root->right)
                dfs(root->right, out + "->", res);
        }
    }
};
