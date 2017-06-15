class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0)
            return false;
        int left = 0;
        int right = A.size() - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(A[left] == A[right] && A[right] == A[mid])
            {
                for(int i = left; i <= right; i++)
                {
                    if(A[i] == target)
                        return true;
                }
                return false;
            }
            if(A[mid] == target)
                return true;
            if(A[left] <= A[mid])
            {
                if(target < A[mid] && target >= A[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if(target > A[mid] && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
