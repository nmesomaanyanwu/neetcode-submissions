class Solution {
vector<vector<int>> ans;
vector<int> path;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(),0);
        backtracking(nums,visited);
        return ans;    

        
    }

private:
    void backtracking(vector<int>& nums,vector<int> visited){
        if (path.size() == nums.size())
            ans.push_back(path);

        for (int i = 0 ; i < nums.size(); i++){
            if (visited[i] == 1){
                continue;
            }
            visited[i] = 1;
            path.push_back(nums[i]);
            backtracking(nums, visited);
            visited[i] = 0;
            path.pop_back();
        } 


    } 
};
