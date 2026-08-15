class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : flights) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        pq.push({0, src, 0});

        // dist[node][stops]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {

            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (auto [v, wt] : adj[u]) {

                int newCost = cost + wt;

                if (newCost < dist[v][stops + 1]) {

                    dist[v][stops + 1] = newCost;

                    pq.push({
                        newCost,
                        v,
                        stops + 1
                    });
                }
            }
        }

        return -1;
 
    }
};