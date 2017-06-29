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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode* helper(vector<int> &inorder, int ileft, int iright, vector<int> &postorder, int pleft, int pright)
    {
        if(ileft > iright || pleft > pright)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pright]);
        int index = 0;
        for(index = ileft; index <= iright; index++)
        {
            if(inorder[index] == postorder[pright])
                break;
        }
        root->left = helper(inorder, ileft, index - 1, postorder, pleft, pleft + index - ileft - 1);
        root->right = helper(inorder, index + 1, iright, postorder, pleft + index - ileft, pright - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
