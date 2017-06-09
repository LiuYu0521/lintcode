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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generate(int beg, int end)
    {
        vector<TreeNode* > ret;
        if (beg > end)
        {
            ret.push_back(NULL);
            return ret;
        }

        for(int i = beg; i <= end; i++)
        {
            vector<TreeNode* > leftTree = generate(beg, i - 1);
            vector<TreeNode* > rightTree = generate(i + 1, end);
            for(int j = 0; j < leftTree.size(); j++)
                for(int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode *node = new TreeNode(i);
                    ret.push_back(node);
                    node->left = leftTree[j];
                    node->right = rightTree[k];
                }
        }

        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generate(1, n);
    }
};
