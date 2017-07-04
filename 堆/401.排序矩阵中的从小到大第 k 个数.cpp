struct cmp{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        priority_queue<int, vector<int>, cmp> q;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                q.push(matrix[i][j]);
                if(q.size() > k)
                    q.pop();
            }
        }
        return q.top();
    }
};
