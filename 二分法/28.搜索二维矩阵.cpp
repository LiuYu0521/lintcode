class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(matrix[mid / n][mid % n] == target)
                return true;
            else if(matrix[mid / n][mid % n] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
