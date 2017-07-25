class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty() || matrix[0].empty())
            return 0;
        if(target < matrix[0][0] || target > matrix.back().back())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1;
        int j = 0;
        int cnt = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] == target)
                cnt++;
            if(matrix[i][j] < target)
                j++;
            else
                i--;
        }
        return cnt;
    }
};
