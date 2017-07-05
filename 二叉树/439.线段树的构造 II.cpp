/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return buildTree(0, A.size() - 1, A);
    }
    SegmentTreeNode* buildTree(int start, int end, vector<int> &A)
    {
        if(start > end)
            return nullptr;
        SegmentTreeNode* node = new SegmentTreeNode(start, end, A[start]);
        if(start == end)
            return node;
        int mid = (start + end) / 2;
        node->left = buildTree(start, mid, A);
        node->right = buildTree(mid + 1, end, A);
        if(node->left)
            node->max = max(node->max, node->left->max);
        if(node->right)
            node->max = max(node->max, node->right->max);
        return node;
    }
};
