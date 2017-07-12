class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        dfs(pos, 0, res);
        return res;
    }
    void dfs(vector<int> &pos, int row, vector<vector<string>> &res)
    {
        int n = pos.size();
        if(row == n)
        {
            vector<string> out(n, string(n, '.'));
            for(int i = 0; i < n; i++)
            {
                out[i][pos[i]] = 'Q';
            }
            res.push_back(out);
        }
        else
        {
            for(int col = 0; col < n; col++)
            {
                if(isValid(row, col, pos))
                {
                    pos[row] = col;
                    dfs(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(int row, int col, vector<int> &pos)
    {
        for(int i = 0; i < row; i++)
        {
            if(pos[i] == col || abs(row - i) == abs(col - pos[i]))
                return false;
        }
        return true;
    }
};
// 在同一个对角线判断|row1 - row2| = |column1 - column2|
// 循环里面有递归，要注意reset状态
