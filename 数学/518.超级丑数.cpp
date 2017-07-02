class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        vector<int> res(1, 1);
        vector<int> idx(primes.size(), 0);
        while(res.size() < n)
        {
            vector<int> temp;
            int mn = INT_MAX;
            for(int i = 0; i < primes.size(); i++)
            {
                temp.push_back(res[idx[i]] * primes[i]);
            }
            for(int i = 0; i < primes.size(); i++)
            {
                mn = min(mn, temp[i]);
            }
            for(int i = 0; i < primes.size(); i++)
            {
                if(mn == temp[i])
                    idx[i]++;
            }
            res.push_back(mn);
        }
        return res.back();
    }
};
