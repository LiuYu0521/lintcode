class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if (n == 1)
            return 1;
        long long ord[n];
        for (int i = 0; i < n; ++i) {
            ord[i] = 1;
            for (int j = 0; j < n; ++j)
                if (A[j] < A[i])
                    ord[i] ++;
        }
        long long F[30];
        F[0] = 1;
        for (int i = 1; i < 15; ++i)
            F[i] = F[i-1] * i;

        long long sum = 0;
        for (int i = 0, k = n-1; i < n-1; i++, k--) {
            sum += (long long)(ord[i] - 1) * F[k];
            for (int j = i + 1; j < n; ++j)
                if (ord[i] < ord[j])
                    ord[j]--;
        }
        return sum + 1;
    }
};
