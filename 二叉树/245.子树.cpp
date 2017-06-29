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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool flag;
    bool check(TreeNode* T1, TreeNode* T2)
    {
        if(!T1 && !T2)
            return true;
        if(!T1 && T2)
            return false;
        if(T1 && !T2)
            return false;
        if(T1->val != T2->val)
            return false;
        return check(T1->left, T2->left) && check(T1->right, T2->right);
    }
    void dfs(TreeNode* T1, TreeNode* T2)
    {
        // if(flag)
        //     return;
        if(check(T1, T2))
        {
            flag = true;
            return;
        }
        if(!T1)
            return;
        dfs(T1->left, T2);
        dfs(T1->right, T2);
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        flag = false;
        dfs(T1, T2);
        return flag;
    }
};
