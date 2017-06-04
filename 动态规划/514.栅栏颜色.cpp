class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if(n == 0 || k == 0)
            return 0;
        int sum[n];
        sum[0] = k;
        sum[1] = k * k;
        for(int i = 2; i < n; i++)
        {
            sum[i] = (k - 1) * (sum[i - 2] + sum[i - 1]);
        }
        return sum[n - 1];
    }
};
