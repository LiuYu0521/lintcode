class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(A[mid] < target)
                left = mid + 1;
            else if(A[mid] > target)
                right = mid - 1;
            else
            {
                break;
            }
        }
        vector<int> res(2, -1);
        if(left <= right)
        {
            int i = mid;
            int j = mid;
            while(A[i - 1] == target)
                i--;
            while(A[j + 1] == target)
                j++;
            res[0] = i;
            res[1] = j;
        }
        return res;
    }
};
