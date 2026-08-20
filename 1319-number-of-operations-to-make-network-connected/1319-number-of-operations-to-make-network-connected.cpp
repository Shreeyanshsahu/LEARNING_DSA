class DisjointSet {
    vector<int> unionrank;
    vector<int> parent;
    

public:
    int extra = 0;
    DisjointSet(int V) {
        unionrank.resize(V + 1, 0);
        parent.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }
    int findsuperparent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findsuperparent(parent[node]);
    }
    bool unionByRank(int u, int v) {
        int superU = findsuperparent(u);
        int superV = findsuperparent(v);
        if (superU == superV) {
            extra++;
            return true;
        }
        if (unionrank[superU] < unionrank[superV]) {
            parent[superU] = superV;

        } else if (unionrank[superU] > unionrank[superV]) {
            parent[superV] = superU;
        } else {
            parent[superV] = superU;
            unionrank[superU]++;
        }
        return extra>0;
    }
};
class Solution {
public:
    int makeConnected(int V, vector<vector<int>>& connections) {

        DisjointSet graph(V);

        for (auto edge : connections) {
            graph.unionByRank(edge[0], edge[1]);
        }

        int components = 0;

        for (int i = 0; i < V; i++) {
            if (graph.findsuperparent(i) == i) {
                components++;
            }
        }

        int needed = components - 1;

        if (graph.extra >= needed) {
            return needed;
        }

        return -1;
    }
};