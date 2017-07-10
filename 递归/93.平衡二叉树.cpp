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
     * @return: True if this Binary tree is Balanced, or false.
     */
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(!root)
            return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) return false;
        else return true;
    }
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        if (right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        else return 1 + max(left, right);
    }
};
