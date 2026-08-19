class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int>(n, 1e8));
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            d[u][v] = wt;
            d[v][u] = wt;
        }
        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
        }
        for (int k = 0; k < d.size(); k++) {
            for (int i = 0; i < d.size(); i++) {
                for (int j = 0; j < d[0].size(); j++) {
                    if (d[i][k] != 1e8 && d[k][j] != 1e8)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int minreach = INT_MAX;
        int minreachcity=0;
        for (int k = 0; k < d.size(); k++) {
            int count =0;
            for (int i = 0; i < d.size(); i++) {
                if(d[i][k]<=distanceThreshold && i!=k){
                    count++;
                }
            }
            if(minreach>=count){
                minreach=count;
                minreachcity=k;
            }
        }
        return minreachcity;
    }
};