class DisjointSet {

public:
    vector<int> parent, rank, size;
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

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet DSU(n * m);
        vector<int> ans;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int maxisland = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                int x = i;
                int y = k;
                if (grid[x][y] == 0) {
                    continue;
                }
                for (int j = 0; j < 4; j++) {
                    if (check(n, m, x + dx[j], y + dy[j]) &&
                        grid[x + dx[j]][y + dy[j]]) {
                        int node = x * m + y;
                        int newX = x + dx[j];
                        int newY = y + dy[j];
                        int adjNode = newX * m + newY;
                        if (DSU.findUPar(node) != DSU.findUPar(adjNode)) {
                            DSU.unionBySize(node,adjNode);
                            int parent = DSU.findUPar(adjNode);
                            maxisland = max(maxisland, DSU.size[parent]);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                int x = i;
                int y = k;
                if (grid[x][y] == 1) {
                    continue;
                }
                int temp = 1;
                set<int> components;
                for (int j = 0; j < 4; j++) {
                    if (check(n, m, x + dx[j], y + dy[j]) &&
                        grid[x + dx[j]][y + dy[j]]) {
                        int node = x * m + y;
                        int newX = x + dx[j];
                        int newY = y + dy[j];
                        int adjNode = newX * m + newY;
                        if (DSU.findUPar(node) != DSU.findUPar(adjNode)) {
                            int v = DSU.findUPar(adjNode);
                            components.insert(v);
                        }
                    }
                }
                for (auto v : components) {
                    temp += DSU.size[v];
                }
                maxisland = max(maxisland, temp);
            }
        }
        if(maxisland==INT_MIN) return 1;
        return maxisland;
    }
};