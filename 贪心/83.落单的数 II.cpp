class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < A.size(); ++j) {
                sum += (A[j] >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};
