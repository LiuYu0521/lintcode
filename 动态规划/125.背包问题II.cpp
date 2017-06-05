class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int len = A.size();
        int dp[m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < len;i++)
        {
            for(int j = m; j > 0; j--)
            {
                if(j >= A[i])
                    dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};

