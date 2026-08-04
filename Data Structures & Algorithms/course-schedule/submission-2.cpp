class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      /*so were gonna have 3 states 
      1. 0 hasnt been explored before 
      2. 1 currently being explored 
      3 2 we have explored and realized that its a valid end 

      ill make a hashmap of courses to its prerequsites 
      then for each course in num courses we will recurse into its path and check if theres a loop and return false 
      */
        unordered_map<int, vector<int>> graph;

        for (int i = 0 ; i < prerequisites.size(); i++){
            vector<int> cur  = prerequisites[i];
            int course = cur[0];
            int pre = cur[1];

            graph[course].push_back(pre);
        }

        vector<int> state(numCourses,0);
        for (int  i = 0 ; i < numCourses; i++){
            //for each state we check if it can produce an end 
            if (!dfs(i , graph , state)){
                return false;
            }
        }

        return true;


    }

private:
        bool dfs(int course ,unordered_map<int, vector<int>>& graph , vector<int> state ){
            if (state[course] == 1){
                return false;
            }
            if (state[course] == 2){
                return true;
            }

            state[course] = 1;
            for (int pre : graph[course]){
                if (! dfs(pre , graph , state)){
                    return false;
                }
            }
            state[course] = 2;

            return true;
        }
};
