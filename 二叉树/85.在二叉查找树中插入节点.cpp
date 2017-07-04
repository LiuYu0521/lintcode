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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(!root)
            return node;
        TreeNode* temp = root;
        while(true)
        {
            if(temp->val < node->val)
            {
                if(temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = node;
                    return root;
                }
            }
            else
            {
                if(temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = node;
                    return root;
                }
            }
        }
    }
};
