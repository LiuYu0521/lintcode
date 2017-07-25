class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long long res = 0;
        bool isPositive = true;
        if(n < 0)
        {
            isPositive = false;
            n = -n;
        }
        while(n > 0)
        {
            res = res * 10 + n % 10;
            n = n / 10;
        }
        if(res > INT_MAX)
            return 0;
        if(!isPositive)
            res = -res;
        return res;
    }
};
