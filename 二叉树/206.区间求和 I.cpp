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
    int start, end;
    long long sum;
    SegmentTree(int start, int end, long long sum = 0): left(NULL), right(NULL), start(start), end(end), sum(sum){};
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
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    static long long query(SegmentTree* root, int start, int end)
    {
        if(start <= root->start && end >= root->end)
            return root->sum;
        if(root->left->end >= end)
            return query(root->left, start, end);
        if(root->right->start <= start)
            return query(root->right, start, end);
        long long leftsum = query(root->left, start, root->left->end);
        long long rightsum = query(root->right, root->right->start, end);
        return leftsum + rightsum;
    }
};
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentTree* root = SegmentTree::build(0, A.size() - 1, A);
        vector<long long> res;
        int len = queries.size();
        for(int i = 0; i < len; i++)
        {
            res.push_back(SegmentTree::query(root, queries[i].start, queries[i].end));
        }
        return res;
    }
};
