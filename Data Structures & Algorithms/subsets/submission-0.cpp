class Solution {
vector<vector<int>> res;
 vector<int> path={};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    dfs(0 , nums);
    return res;


        
    }
private:
    void dfs(int index ,vector<int>& nums ){
        
        res.push_back(path);

        for (int i = index ; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i+1 , nums);
            path.pop_back();

        }
    }

};
