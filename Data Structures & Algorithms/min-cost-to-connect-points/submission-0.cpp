class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();

        vector<vector<pair<int,int>>> adj(v);

        for(int i = 0; i < v; i++){
            for(int j = i + 1; j < v; j++){
                int dist = abs(points[i][0] - points[j][0]) +abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<bool> visited(v, false);

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        visited[0] = true;

        for(auto [next, wt] : adj[0])
            pq.push({wt, 0, next});

        int ans = 0;

        while(!pq.empty()){
            auto [wt, parent, node] = pq.top();
            pq.pop();

            if(visited[node]) continue;

            visited[node] = true;
            ans += wt;

            for(auto [next, weight] : adj[node]){
                if(!visited[next])
                    pq.push({weight, node, next});
            }
        }

        return ans;
    }
};