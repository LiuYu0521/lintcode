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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(!root || A == root || B == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, A, B);
        if(left && left != A && left != B)
            return left;
        TreeNode* right = lowestCommonAncestor(root->right, A, B);
        if(right && right != A && right != B)
            return right;
        if(left && right)
            return root;
        return left ? left : right;
    }
};
