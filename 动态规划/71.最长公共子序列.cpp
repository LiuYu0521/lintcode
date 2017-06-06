class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int lenA=A.size();
        int lenB=B.size();
        int dp[lenA+1][lenB+1];
        for(int i=0;i<=lenA;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=lenB;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<lenA;i++)
        {
            for(int j=0;j<lenB;j++)
            {
                if(A[i]==B[j])
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else
                {
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[lenA][lenB];
    }
};
