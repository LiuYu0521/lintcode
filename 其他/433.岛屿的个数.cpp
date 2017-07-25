class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] && !visited[i][j])
                {
                    dfs(i, j, grid, visited);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<bool>> &grid, vector<vector<bool>> &visited)
    {
        if(i < 0 || i >= grid.size())
            return;
        if(j < 0 || j >= grid[0].size())
            return;
        if(!grid[i][j] || visited[i][j])
            return;
        visited[i][j] = true;
        dfs(i - 1, j, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i, j + 1, grid, visited);
    }
};
