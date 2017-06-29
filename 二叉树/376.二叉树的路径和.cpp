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
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> res;
        if(!root)
            return res;
        int path_sum = 0;
        vector<int> order;
        findPath(root, target, res, order, path_sum);
        return res;
    }
    void findPath(TreeNode* root, int target, vector<vector<int>> &res, vector<int> &order, int &path_sum)
    {
        path_sum = path_sum + root->val;
        order.push_back(root->val);
        if(path_sum == target && !root->left && !root->right)
            res.push_back(order);
        if(root->left)
            findPath(root->left, target, res, order, path_sum);
        if(root->right)
            findPath(root->right, target, res, order, path_sum);
        path_sum = path_sum - root->val;
        order.pop_back();

    }
};
