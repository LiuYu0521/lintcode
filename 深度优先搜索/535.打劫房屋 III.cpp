/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        if(!root)
            return 0;
        int res = 0;
        if(root->left)
            res = res + houseRobber3(root->left->left) + houseRobber3(root->left->right);
        if(root->right)
            res = res + houseRobber3(root->right->left) + houseRobber3(root->right->right);
        return max(res + root->val, houseRobber3(root->left) + houseRobber3(root->right));
    }
};

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        unordered_map<TreeNode*, int> m;
        return dfs(root, m);
    }
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &m)
    {
        if(!root)
            return 0;
        if(m.count(root))
            return m[root];
        int res = 0;
        if(root->left)
            res = res + dfs(root->left->left, m) + dfs(root->left->right, m);
        if(root->right)
            res = res + dfs(root->right->left, m) + dfs(root->right->right, m);
        res = max(res + root->val, dfs(root->left, m) + dfs(root->right, m));
        m[root] = res;
        return res;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode* root)
    {
        vector<int> res(2, 0);
        if(!root)
            return res;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
    }
};
