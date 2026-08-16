class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // So this will be are adjacency list
        int ans = 0;
        vector<int> visited(n,0);

        for (int i = 0; i < edges.size(); i++){
            vector<int> cur = edges[i];
            graph[cur[0]].push_back(cur[1]);
            graph[cur[1]].push_back(cur[0]);
        }

        auto dfs = [&](auto&& self , int parent , int node)->void{
            if (visited[node] == 2){
                return;
            }
            visited[node] = 2;

            for (auto nei : graph[node]){
                if (nei == parent){
                    continue;
                }
                if (visited[nei] == 2){
                    continue;
                }

                self(self , node , nei);
            }
        };

        for (int i = 0 ; i < n; i++){
            if ( visited[i] == 0){
                ans++;
                dfs(dfs, -1 , i);
            }
        }

        return ans;

    }
};
