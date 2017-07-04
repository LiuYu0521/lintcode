class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void downAdjust(vector<int> &A, int i, int len)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if(l < len)
            if(A[l] < A[i])
                smallest = l;
        if(r < len)
            if(A[r] < A[smallest])
                smallest = r;
        if(smallest != i)
        {
            swap(A[i], A[smallest]);
            downAdjust(A, smallest, len);
        }
    }
    void heapify(vector<int> &A) {
        // write your code here
        int len = A.size();
        for(int i = len / 2; i >= 0; i--)
        {
            downAdjust(A, i, len);
        }
    }
};
