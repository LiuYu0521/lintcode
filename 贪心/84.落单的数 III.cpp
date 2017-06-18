class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int x = 0, len = A.size(), pos;
        for(int i = 0; i < len; i++)
        {
            x ^= A[i];
        }
        for(int i = 0; i < 32; i++)
        {
            if((x >> i) & 1)
            {
                pos = i;
                break;
            }
        }
        vector<int> res(2);
        for(int i = 0; i < len; i++)
        {
            if((A[i] >> pos) & 1)
                res[0] ^= A[i];
            else
                res[1] ^= A[i];
        }
        return res;
    }
};
