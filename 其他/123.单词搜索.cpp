class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if(word.empty())
            return true;
        if(board.empty() || board[0].empty())
            return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(dfs(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int k, int i, int j, vector<vector<bool>> &visited)
    {
        if(k == word.length())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[k])
            return false;
        visited[i][j] = true;
        bool res = dfs(board, word, k + 1, i - 1, j, visited)
        || dfs(board, word, k + 1, i, j - 1, visited)
        || dfs(board, word, k + 1, i + 1, j, visited)
        || dfs(board, word, k + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};
