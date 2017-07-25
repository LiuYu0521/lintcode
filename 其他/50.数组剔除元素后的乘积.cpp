class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len == 1)
            return vector<long long>(len, 1);
        vector<long long> A(len, 1);
        vector<long long> B(len, 1);
        vector<long long> res(len, 1);
        for(int i = 0; i < len; i++)
        {
            if(i == 0)
            {
                A[i] = nums[i];
                B[len - i - 1] = nums[len - i - 1];
            }
            else
            {
                A[i] = A[i - 1] * nums[i];
                B[len - i - 1] = B[len - i] * nums[len - i - 1];
            }
        }
        res[0] = B[1];
        res[len - 1] = A[len - 2];
        for(int i = 1; i <= len - 2; i++)
        {
            res[i] = A[i - 1] * B[i + 1];
        }
        return res;
    }
};
