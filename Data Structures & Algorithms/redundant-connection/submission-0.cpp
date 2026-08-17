class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int s = edges.size();
        vector<vector<int>> graph(s+ 1); // build our adjacency list
        vector<pair<int,int>> candidates;

        for (int i = 0; i < edges.size(); i++){
            vector<int> cur = edges[i];
            graph[cur[0]].push_back(cur[1]);
            graph[cur[1]].push_back(cur[0]);

        }
        
        vector<int> visited(s + 1, 0);

        auto dfs = [&](auto&& self, int node, int parent)->void{

            visited[node] = 1 ; // starting current path

            for (auto nei : graph[node]){
                if (nei == parent){
                    continue;
                }
                if (visited[nei] == 1){
                    candidates.push_back({nei, node});
                    continue;
                }

                self(self , nei, node);
                visited[nei] = 0; //backtracking
                
            }
            visited[node] = 0;
            return;

        };

        for (int i = 1 ; i < s + 1 ; i++){
            dfs(dfs, i , -1);
        }
        
        if (candidates.size()!= 1){
             for (int i = edges.size() - 1; i >= 0; i--) {

                auto cur = edges[i];

                int r = cur[0];
                int c = cur[1];

                for (auto& [v, h] : candidates) {

                    if ((v == r && c == h) ||
                        (v == c && r == h)) {

                        return {r, c};
                    }
                }
            }
        }
        else if (candidates.size() == 1){
            int a = candidates[0].first;
            int b = candidates[0].second;

            for (auto& edge : edges) {
                if ((edge[0] == a && edge[1] == b) ||
                    (edge[0] == b && edge[1] == a)) {
                    return edge;
                }
            }
        }

        return {};
    
    }
};
