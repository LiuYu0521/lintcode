class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                process(i, 0, board);
            if(board[i][n - 1] == 'O')
                process(i, n - 1, board);
        }
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
                process(0, j, board);
            if(board[m - 1][j] == 'O')
                process(m - 1, j, board);
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'E')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void process(int i, int j, vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        typedef pair<int, int> point;
        queue<point> q;
        q.push(point(i, j));
        board[i][j] = 'E';
        while(!q.empty())
        {
            point temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second;
            if (x!=0&&board[x-1][y]=='O')
            {
                q.push(point(x-1,y));
                board[x-1][y]='E';   //extended;
            }
            if (x!=m-1&&board[x+1][y]=='O')
            {
                q.push(point(x+1,y));
                board[x+1][y]='E';   //extended;
            }
            if (y!=0&&board[x][y-1]=='O')
            {
                q.push(point(x,y-1));
                board[x][y-1]='E';   //extended;
            }
            if (y!=n-1&&board[x][y+1]=='O')
            {
                q.push(point(x,y+1));
                board[x][y+1]='E';   //extended;
            }
        }
    }
};
