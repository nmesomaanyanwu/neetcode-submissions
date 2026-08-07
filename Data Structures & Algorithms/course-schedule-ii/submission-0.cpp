class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // this is the map we will us to map courses : prerequisites
        unordered_map<int , vector<int>> graph;
        vector<int> visited(numCourses+ 1, 0);
        vector<int> ans;

        for (int i = 0; i < prerequisites.size(); i++){
            vector<int> current = prerequisites[i];
            int courses = current[0];
            int pre = current[1];
            
            graph[courses].push_back(pre);

        }

        // now we recursively go through each tree 
        for (int course = 0 ; course < numCourses ; course++){
            if (!dfs(course , graph , visited, ans)){
                return {};
            }
            
        }

        return ans;
    }
private:
    bool dfs(int course ,unordered_map<int , vector<int>>& graph , vector<int>& visited, vector<int>& ans){
        // base cases
        if (visited[course] == 1){
            return false;
        }

        if (visited[course] == 2){
            return true;
        }

        visited[course] = 1;

        for (auto pre : graph[course]){
            if (!dfs(pre , graph , visited, ans)){
                return false;
            }
            
        }
        
        visited[course] = 2;
        ans.push_back(course);
        return true;
    }
};
