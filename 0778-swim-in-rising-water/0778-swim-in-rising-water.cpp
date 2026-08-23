class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
    bool check(int m, int n, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<pair<int,pair<int,int>>> DSUorder;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                DSUorder.push_back({grid[i][j],{i,j}});
            }
        }
        sort(DSUorder.begin(),DSUorder.end());
        DisjointSet DSU(n*m);
        int time = 0;
        for(int i =0;i<n*m;i++){
            auto [ele,cord]=DSUorder[i];
            auto [x,y]=cord;
            time=ele;
            visited[x][y]=1;
            for (int j = 0; j < 4; j++) {
                    if (check(n, m, x + dx[j], y + dy[j]) &&
                        visited[x + dx[j]][y + dy[j]]) {
                        int node = x * m + y;
                        int newX = x + dx[j];
                        int newY = y + dy[j];
                        int adjNode = newX * m + newY;
                        if (DSU.findUPar(node) != DSU.findUPar(adjNode)) {
                            DSU.unionBySize(node,adjNode);
                        }
                    }
            }
            if(DSU.findUPar(n*m-1)==DSU.findUPar(0)) return time;
        }
        return 0;
    }
};