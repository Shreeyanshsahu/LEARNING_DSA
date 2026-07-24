class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> ans(board.size(),
                                 vector<char>(board[0].size(), 'X'));
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        queue<pair<int, int>> q;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (i == 0 || i == m - 1) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                        vis[i][j] = 1;
                        ans[i][j] = 'O';
                    }
                }
            } else {
                if (board[i][0] == 'O') {
                    q.push({i, 0});
                    vis[i][0] = 1;
                    ans[i][0] = 'O';
                }

                if (board[i][n - 1] == 'O') {
                    q.push({i, n - 1});
                    vis[i][n - 1] = 1;
                    ans[i][n-1] = 'O';
                }
            }
        }

        while(!q.empty()){
            int z = q.size();
            while (z > 0) {
                auto [x, y]=q.front();
                z--;
                q.pop();
                if(x+1<m && vis[x+1][y]==0 && board[x+1][y]=='O'){
                    vis[x+1][y]=1;
                    q.push({x+1,y});
                    ans[x+1][y]='O';
                }
                if(x-1>-1 && vis[x-1][y]==0 && board[x-1][y]=='O'){
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                    ans[x-1][y]='O';
                }
                if(y+1<n && vis[x][y+1]==0 && board[x][y+1]=='O'){
                    vis[x][y+1]=1;
                    q.push({x,y+1});
                    ans[x][y+1]='O';
                }
                if(y-1>-1 && vis[x][y-1]==0 && board[x][y-1]=='O'){
                    vis[x][y-1]=1;
                    q.push({x,y-1});
                    ans[x][y-1]='O';
                }
            }
        }
        board=ans;
    }
};