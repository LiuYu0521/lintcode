/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class SegmentTree{
public:
    SegmentTree *left, *right;
    int start, end, min;
    SegmentTree(int start, int end, int min = 0):left(NULL), right(NULL), start(start), end(end), min(min){};
    static SegmentTree* build(int start, int end, vector<int> &a)
    {
        if(start > end)
            return nullptr;
        SegmentTree* node = new SegmentTree(start, end, a[start]);
        if(start == end)
            return node;
        int mid = (start + end) / 2;
        node->left = build(start, mid, a);
        node->right = build(mid + 1, end, a);
        node->min = node->left->min < node->right->min ? node->left->min : node->right->min;
        return node;
    }
    static int query(SegmentTree* root, int start, int end)
    {
        if(start <= root->start && end >= root->end)
            return root->min;
        if(root->left->end >= end)
            return query(root->left, start, end);
        if(root->right->start <= start)
            return query(root->right, start, end);
        int leftmin = query(root->left, start, root->left->end);
        int rightmin = query(root->right, root->right->start, end);
        return leftmin < rightmin ? leftmin : rightmin;
    }
};
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentTree* root = SegmentTree::build(0, A.size() - 1, A);
        vector<int> res;
        int len = queries.size();
        for(int i = 0; i < len; i++)
        {
            res.push_back(SegmentTree::query(root, queries[i].start, queries[i].end));
        }
        return res;
    }
};
