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

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        int removestone = 0;
        int totalstones = stones.size();
        DisjointSet DSU(totalstones);
        for (int i = 0; i < totalstones; i++) {

            int x = stones[i][0];
            int y = stones[i][1];

            if (row.find(x) != row.end()) {
                DSU.unionByRank(row[x], i);
            }
            if (col.find(y) != col.end()) {
                DSU.unionByRank(col[y], i);
            }
            row[x] = i;
            col[y] = i;
        }
        int component = 0;
        for (int i = 0; i < totalstones; i++) {
            if (DSU.findUPar(i) == i) {
                component++;
            }
        }
        return abs(totalstones - component);
    }
};