class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int len = A.size();
        if(len == 0 || len == 1)
            return true;
        bool dp[len];
        dp[0] = true;
        for(int i = 1; i < len; i++)
        {
            dp[i] = dp[i - 1] && (A[i - 1] >= i);
        }
        return dp[len - 1];
    }
};
