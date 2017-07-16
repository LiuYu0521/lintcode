class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.length(), n = B.length(), res = 0;
        int dp[m + 1][n + 1];
        for(int i = 0; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
