class Solution {
public:
    int countPaths(int V, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(V);

        for (auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        const int MOD = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {

                long long newDist = dist[u] + w;

                if (newDist < dist[v]) {

                    dist[v] = newDist;
                    ways[v] = ways[u];

                    pq.push({dist[v], v});
                }
                else if (newDist == dist[v]) {

                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V - 1];
    }
};