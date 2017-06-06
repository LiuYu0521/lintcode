class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int lenS = S.length();
        int lenT = T.length();
        int dp[lenS + 1][lenT + 1];
        dp[0][0] = 1;
        for(int i = 1; i <= lenS; i++)
        {
            dp[i][0] = 1;
        }
        for(int j = 1; j <= lenT; j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1; i <= lenS; i++)
        {
            for(int j = 1; j <= lenT; j++)
            {
                if(S[i - 1] == T[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[lenS][lenT];
    }
};
