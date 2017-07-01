class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
        int a = 0;
        int b = 1;
        int res;
        for(int i = 0; i < n - 2; i++)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};
