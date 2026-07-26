class Solution {
vector<vector<int>> res;
vector<int> path;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0 , candidates, target);
        return res;  
        


    }
private:
    void dfs(int index ,vector<int>& nums, int remaining ){

        if (remaining == 0){
            if (find(res.begin(), res.end(), path) == res.end()) {
        res.push_back(path);
    }
            return; 
        }
        if (remaining < 0){
            return;
        }

        for (int i = index ;i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i+ 1 , nums , remaining -nums[i]);
            path.pop_back(); 

        }
    }

};
