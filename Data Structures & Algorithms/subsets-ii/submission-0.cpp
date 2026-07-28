class Solution {
vector<vector<int>> ans{};
vector<int> path{};
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0 ,nums);
        return ans;
    }

private:

    void backtrack(int d, vector<int>& nums){
        sort(path.begin(), path.end());
       if (find(ans.begin(), ans.end(), path) == ans.end()){ 
        ans.push_back(path);
       }
        for (int i = d ; i < nums.size();i++) {
            path.push_back(nums[i]);
            backtrack(i+ 1, nums);
            path.pop_back(); 
        }

        return;

    }
};
