class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*i think since we can start from any node i will try and  and use a visited to show if we reach the last node
        We use a set to track the amount of nodes we seen once the size of the set is equal to the number of nodes we return  immediately  else i thik we return -1 
        */

        unordered_set<int> visited;
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto cur : times){
            int start = cur[0];
            int end = cur[1];
            int time = cur[2];

            graph[start].push_back({end , time});
        }
        
        auto compare = [](vector<int> a , vector<int>b){
            return a[1] > b[1]; // time is less 
        };

        int min_time = 0;

        priority_queue<vector<int> , vector<vector<int>>, decltype(compare)> q(compare);

        q.push({k , 0});

        while (!q.empty()){
            vector<int> cur = q.top();
            q.pop();
            int s = cur[0];
            int t = cur[1];
            if (visited.count(s))continue;
            visited.insert(s);
            if (visited.size() == n) return  t;

            for (auto [nei , nt]: graph[s]){
                if (visited.count(nei)) continue;

                q.push({nei , t + nt });
            }
        };

        return -1;

        
    }
};
