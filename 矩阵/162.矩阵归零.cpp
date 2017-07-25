class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        if(matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row[m], col[n];
        for(int i = 0; i < m; i++)
        {
            row[i] = false;
        }
        for(int j = 0; j < n; j++)
        {
            col[j] = false;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
