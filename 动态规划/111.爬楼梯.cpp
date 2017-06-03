class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n == 0 || n == 1)
            return 1;
        int sum[n + 1];
        sum[0] = 1;
        sum[1] = 1;
        for(int i = 2; i < n + 1; i++)
        {
            sum[i] = sum[i - 2] + sum[i - 1];
        }
        return sum[n];
    }
};
