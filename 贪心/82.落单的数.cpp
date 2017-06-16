class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int len = A.size();
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            res = res ^ A[i];
        }
        return res;
    }
};
