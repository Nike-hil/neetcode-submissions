class Solution {
public:
    vector<int> dijkstra(int v,unordered_map<int, vector<pair<int,int>>> &adj,int src) {

        vector<int> dist(v + 1, INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [next, wt] : adj[node]) {
                if (dist[next] > d + wt) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> res = dijkstra(n, adj, k);

        int mx = *max_element(res.begin() + 1, res.end());

        return mx == INT_MAX ? -1 : mx;
    }
};