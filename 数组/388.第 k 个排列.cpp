class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for(int i = 1; i < n; i++)
            f[i] = f[i - 1] * i;
        k--;
        for(int i = n; i >= 1; i--)
        {
            int a = k / f[i - 1];
            k = k % f[i - 1];
            res.push_back(num[a]);
            num.erase(a, 1);
        }
        return res;
    }
};
