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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root)
            return res;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> oneLevel;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                oneLevel.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};
