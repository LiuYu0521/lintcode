class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        int length = A.size();
        for(int i = 0; i < length-1; i++)
        {
            int minnum = A[i];
            int index = i;
            for(int j = i + 1; j < length; j++)
            {
                if(A[j] < minnum)
                {
                    minnum = A[j];
                    index = j;
                }
            }
            swap(A[i], A[index]);
        }
    }
};
