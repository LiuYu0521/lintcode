class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int l = -1;
        dp[0][0] = matrix[0][0];
        for(int i = 1; i < m; i++)
        {
            dp[i][0] = matrix[i][0];
        }
        for(int j = 1; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                l = max(l, dp[i][j]);
            }
        }
        return l*l;
    }
};
