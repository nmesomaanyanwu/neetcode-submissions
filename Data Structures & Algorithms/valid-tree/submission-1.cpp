class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // this is are vector of nodes -> neighbours 
        vector<bool> visited(n , false); // nothing has been visited so far
        queue<pair<int,int>> current; // queue handles pairs node ,parent

        // lets make are adjacency list
        for (auto& cur : edges){
            int node = cur[0];
            int nei = cur[1];

            graph[node].push_back(nei);
            graph[nei].push_back(node);
        }

        
        current.push({0,-1}); // 
        visited[0] = true;
        while (!current.empty()){
            auto [node,parent] = current.front(); // get current node 
            current.pop();
            // now check its neigh
            
            for (auto nei : graph[node]){
                    // check if neigh is equal to its parent
                if (nei == parent){
                    continue;
                }
                if (visited[nei]){
                    return false;
                }
                    
                current.push({nei,node});
                visited[nei] = true;
            }

        }

        for (int i = 0 ; i < n;i++){
            if (visited[i] == false){
                return false;
            }
        }

        return true;


    }
};
