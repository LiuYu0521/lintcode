class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i] < A[i - 1])
                return i - 1;
        }
        return A.size() - 1;
    }
};
