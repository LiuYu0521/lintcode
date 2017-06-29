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
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(!root || (!root->left && !root->right))
            return;
        if(root->left && root->right)
        {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        else if(root->left && !root->right)
        {
            root->right = root->left;
            root->left = nullptr;
        }
        else if(!root->left && root->right)
        {
            root->left = root->right;
            root->right = nullptr;
        }
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
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
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(!root || (!root->left && !root->right))
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
};

