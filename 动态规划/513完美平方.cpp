class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        int dp[n + 1];
        for(int i = 0;i <= n; i++)
        {
            dp[i] = i;
        }
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
