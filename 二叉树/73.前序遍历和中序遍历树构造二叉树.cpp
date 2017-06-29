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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode* helper(vector<int> &preorder, int pleft, int pright, vector<int> &inorder, int ileft, int iright)
    {
        if(pleft > pright || ileft > iright)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pleft]);
        int index = 0;
        for(index = ileft; index <= iright; index++)
        {
            if(inorder[index] == root->val)
                break;
        }
        root->left = helper(preorder, pleft + 1, pleft + index - ileft, inorder, ileft, index - 1);
        root->right = helper(preorder, pleft + index - ileft + 1, pright, inorder, index + 1, iright);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
