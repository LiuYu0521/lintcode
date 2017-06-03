class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        int min_sub = INT_MAX;
        int lenB = B.size();
        for(int i = 0; i < lenB; i++)
        {
            int index = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
            min_sub = min(min_sub, abs(B[i] - A[index]));
            if(index > 0)
                min_sub = min(min_sub, abs(B[i] - A[index - 1]));
        }
        return min_sub;
    }
};
