class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if(n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }
    double power(double x, int n)
    {
        if(n == 0)
            return 1;
        double half = power(x, n / 2);
        if(n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};
