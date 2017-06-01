class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void quickSort(vector<int> &A, int left, int right)
    {
        if(left >= right)
            return;
        int i = left;
        int j = right;
        int pivot = A[(left + right) / 2];
        while(i <= j)
        {
            while(A[i] < pivot && i <= j)
                i++;
            while(A[j] > pivot && i <= j)
                j--;
            if(i <= j)
            {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        quickSort(A, i, right);
        quickSort(A, left, j);
    }
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        quickSort(A, 0, A.size() - 1);
    }
};
