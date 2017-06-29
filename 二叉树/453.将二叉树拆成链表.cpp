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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        if(!root)
            return;
        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right)
            root = root->right;
        root->right = temp;
    }
};

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        if(!root)
            return;
        while(root)
        {
            if(root->left)
            {
                TreeNode* pre = root->left;
                while(pre->right)
                    pre = pre->right;
                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
