class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& visit){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visit[i][j]||grid[i][j]=='0'){
            return;
        }
        visit[i][j]=true;
        dfs(i+1,j,grid,visit);//left
        dfs(i-1,j,grid,visit);//right
        dfs(i,j+1,grid,visit);//down
        dfs(i,j-1,grid,visit);//up
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
       vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));

        int island=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visit[i][j]){
                    dfs(i,j,grid,visit);
                    island++;
                }
            }
        }
        return island;
    }
};