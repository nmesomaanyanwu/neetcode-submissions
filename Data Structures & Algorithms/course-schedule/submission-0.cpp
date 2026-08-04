class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> visited;

        for (int i = 0; i < prerequisites.size(); i++){
            // 
            vector<int> current = prerequisites[i];
            int first = current[0];
            int second = current[1];

            if (visited.count(first) == 1 && visited.count(second)== 1){
                return false;
            }
            else if(visited.count(first) == 1 && visited.count(second) == 0)       {
                visited.insert(second);
            }
            else if(visited.count(second) == 1 && visited.count(first) == 0){
                visited.insert(first);
            }
            else{
                visited.insert(first);
                visited.insert(second);
            }

            
        }

        return true;
    }
};
