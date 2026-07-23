class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> distance(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int m = mat.size();
        int n = mat[0].size();
        while (!q.empty()) {
            int z = q.size();
            while (z > 0) {
                auto [cord, dist] = q.front();
                auto [x, y] = cord;
                z--;
                q.pop();
                distance[x][y]=dist;
                if(x+1<m && vis[x+1][y]==0 && mat[x+1][y]==1){
                    vis[x+1][y]=1;
                    q.push({{x+1,y},dist+1});
                }
                if(x-1>-1 && vis[x-1][y]==0 && mat[x-1][y]==1){
                    vis[x-1][y]=1;
                    q.push({{x-1,y},dist+1});
                }
                if(y+1<n && vis[x][y+1]==0 && mat[x][y+1]==1){
                    vis[x][y+1]=1;
                    q.push({{x,y+1},dist+1});
                }
                if(y-1>-1 && vis[x][y-1]==0 && mat[x][y-1]==1){
                    vis[x][y-1]=1;
                    q.push({{x,y-1},dist+1});
                }
            }
        }
        return distance;
    }
};