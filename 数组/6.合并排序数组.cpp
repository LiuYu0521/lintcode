class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> res;
        int lenA = A.size();
        int lenB = B.size();
        int i = 0, j = 0;
        while(i < lenA && j < lenB)
        {
            if(A[i] <= B[j])
            {
                res.push_back(A[i]);
                i++;
            }
            else
            {
                res.push_back(B[j]);
                j++;
            }
        }
        if(i < lenA)
        {
            for(; i < lenA; i++)
            {
                res.push_back(A[i]);
            }
        }
        if(j < lenB)
        {
            for(; j < lenB; j++)
            {
                res.push_back(B[j]);
            }
        }
        return res;
    }
};
