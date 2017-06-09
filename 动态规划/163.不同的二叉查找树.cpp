class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int dp[n + 1];
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            int sum = 0;
            for(int j = 0; j <= i - 1; j++)
            {
                sum = sum + dp[j] * dp[i - 1 - j];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};
