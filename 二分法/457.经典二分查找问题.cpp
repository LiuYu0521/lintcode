class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        int left = 0;
        int right = A.size() - 1;
        int mid = left + (right - left) / 2;
        while(left <= right)
        {
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return -1;
    }
};
