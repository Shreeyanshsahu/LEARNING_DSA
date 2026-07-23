class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        //bfs
        while(!q.empty()){
            
            int size = q.size();
            bool change = false;
            while(size>0){
                size--;
                auto [x,y]=q.front();
                q.pop();
                //right
                if(x+1<m && y<n && grid[x+1][y]==1){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                    change=true;
                }
                //left
                 if(x-1>=0 && y<n && grid[x-1][y]==1){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                    change=true;
                }
                //up
                 if(x<m && y+1<n && grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                    change=true;
                }
                //down
                 if(x<m && y-1>=0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                    change=true;
                }
                
            }
            if(change)time++;
        }
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};