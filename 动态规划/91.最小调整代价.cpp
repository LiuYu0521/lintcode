class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int len = A.size();
        int dp[len + 1][101];
        for(int j = 0; j < 101; j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1;i <= len; i++)
        {
            for(int j = 1; j <=100; j++)
            {
                dp[i][j] = INT_MAX;
                for(int k = max(1, j - target); k <= min(100, j + target); k++)
                {
                    dp[i][j] =min(dp[i][j], dp[i - 1][k] + abs(A[i - 1] - j));
                }
            }
        }
        int res = INT_MAX;
        for(int i = 1; i <= 100; i++)
        {
            res = min(res, dp[len][i]);
        }
        return res;
    }
};
