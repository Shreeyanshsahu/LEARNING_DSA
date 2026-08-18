class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
        // adj[u] = list of {v, weight}
        vector<int> dist(V+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>
            pq; // min-heap

        dist[src] = 0;
        pq.push({0, src}); // {distance, node}

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue; // stale entry, skip

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight});
        }
        vector<int>dist=dijkstra(n,adj,k);
        int maximum = INT_MIN;
        for(int i =1;i<=n;i++){
            if(i==k) continue;
            maximum = max(maximum,dist[i]);
        }
        if(maximum==INT_MAX) return -1;
        return maximum;
    }
};