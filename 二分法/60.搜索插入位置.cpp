class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
