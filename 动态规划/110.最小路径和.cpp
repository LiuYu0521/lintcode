class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m = grid.size();
        int n = grid[0].size();
        int sum[m][n];
        sum[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
        {
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++)
        {
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }
        return sum[m - 1][n - 1];
    }
};
