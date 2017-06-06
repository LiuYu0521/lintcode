class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int len = A.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return A[0];
        long long dp[len + 1];
        dp[0] = 0;
        dp[1] = A[0];
        for(int i = 2; i <= len; i++)
        {
            dp[i] = max(A[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[len];
    }
};
