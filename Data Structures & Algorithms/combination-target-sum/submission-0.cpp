class Solution {
vector<vector<int>> res;
vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0 , nums , target);
        return res;
    }
private:
    void dfs(int index , vector<int>& nums, int remaining){
        if (remaining == 0){
            res.push_back(path);
            return;}
        if (remaining < 0)  return;

        for (int i = index ; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i , nums  , remaining-nums[i]);
            path.pop_back();
        }
    }
};
