class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int sum[m][n];
        sum[0][0] = 1 - obstacleGrid[0][0];
        for(int i = 1; i < m; i++)
        {
            if(sum[i - 1][0] == 0)
                sum[i][0] = 0;
            else
                sum[i][0] = 1 - obstacleGrid[i][0];
        }
        for(int j = 1; j < n; j++)
        {
            if(sum[0][j - 1] == 0)
                sum[0][j] = 0;
            else
                sum[0][j] = 1 - obstacleGrid[0][j];
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    sum[i][j] = 0;
                else
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1];
            }
        }
        return sum[m-1][n-1];
    }
};
