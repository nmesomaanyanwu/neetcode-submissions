class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*We can do a topological sort */
        int n = tickets.size();
        unordered_map<string , vector<string>> graph;

        for (int i = 0 ; i < n ; i++){
            vector<string> cur = tickets[i];
            graph[cur[0]].push_back(cur[1]);
        }
        
        for (auto [node , des]: graph){
            sort(des.rbegin() , des.rend());
        }
        vector<string> output;

        auto dfs = [&](auto&& self , const string& key)-> void{

            while (!graph[key].empty()){
                string cur = graph[key].back();
                graph[key].pop_back();
                self(self, cur);
            }
            output.push_back(key);
        
        };

        
        dfs(dfs, "JFK");
       

        reverse(output.begin() , output.end());

        return output;
    }
};
