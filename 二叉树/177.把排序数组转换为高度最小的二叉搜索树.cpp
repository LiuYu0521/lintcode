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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode* helper(vector<int> &A, int left, int right)
    {
        if(left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* cur = new TreeNode(A[mid]);
        cur->left = helper(A, left, mid - 1);
        cur->right = helper(A, mid + 1, right);
        return cur;
    }
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return helper(A, 0, A.size() - 1);
    }
};


