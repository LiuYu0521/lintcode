class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> z;
        if (matrix.size()==0) return z;
        else
            if (matrix[0].size()==0) return z;
        int x, y, dx, dy, count, m, n;
        x = y = 0;
        count = 1;
        dx = -1; dy = 1;
        m = matrix.size();
        n = matrix[0].size();
        z.push_back(matrix[0][0]);
        while (count<m*n) {
            if (x+dx>=0 && y+dy>=0 && x+dx<m && y+dy<n) {
                x += dx; y += dy;
            }
            else
                if (dx==-1 && dy == 1) {
                    if (y+1<n) ++y; else ++x;
                    dx = 1; dy = -1;
                }
                else {
                    if (x+1<m) ++x; else ++y;
                    dx = -1; dy = 1;
                }
            z.push_back(matrix[x][y]); ++count;
        }
        return z;
    }
};
