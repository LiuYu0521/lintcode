class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int n = costs.size();
        if(n == 0)
            return 0;
        int dp[n][3];
        for(int i = 0; i <= 2; i++)
        {
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= 2; j++)
            {
                dp[i][j] = INT_MAX;
                for(int k = 0; k <= 2; k++)
                {
                    if(k != j)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                    }
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i <= 2; i++)
        {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};
