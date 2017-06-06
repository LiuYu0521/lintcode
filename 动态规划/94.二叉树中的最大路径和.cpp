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
     * @return: An integer
     */
    int ans;
    int solve_dp(TreeNode* root)
    {
        if(!root)
            return 0;
        int sum = root->val;
        int lf = 0;
        int rt = 0;
        if(root->left)
            lf = solve_dp(root->left);
        if(root->right)
            rt = solve_dp(root->right);
        if(lf > 0)
            sum = sum + lf;
        if(rt > 0)
            sum = sum + rt;
        ans = max(ans, sum);
        return max(0, max(lf, rt) + root->val);
    }
    int maxPathSum(TreeNode *root) {
        // write your code here
        if(!root)
            return 0;
        ans = INT_MIN;
        solve_dp(root);
        return ans;
    }
};
