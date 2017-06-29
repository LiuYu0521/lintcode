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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if(!root)
            return res;
        stack <TreeNode*> s1;
        stack <TreeNode*> s2;
        s1.push(root);
        vector<int> oneLeval;
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                TreeNode* node = s1.top();
                s1.pop();
                oneLeval.push_back(node->val);
                if(node->left)
                    s2.push(node->left);
                if(node->right)
                    s2.push(node->right);
            }
            if(!oneLeval.empty())
                res.push_back(oneLeval);
            oneLeval.clear();
            while(!s2.empty())
            {
                TreeNode* node = s2.top();
                s2.pop();
                oneLeval.push_back(node->val);
                if(node->right)
                    s1.push(node->right);
                if(node->left)
                    s1.push(node->left);
            }
            if(!oneLeval.empty())
                res.push_back(oneLeval);
            oneLeval.clear();
        }
        return res;
    }
};
