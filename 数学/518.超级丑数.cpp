class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        int res = 0;
        int count = 0;
        while(count != n)
        {
            res++;
            int temp = res;
            for(int i = 0; i < primes.size(); i++)
            {
                while(temp % primes[i] == 0)
                    temp = temp / primes[i];
            }
            if(temp == 1)
                count++;
        }
        return res;
    }
};
