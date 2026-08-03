class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> n;

        for (int i = 0 ; i < nums.size(); i++){

            if (n.count(nums[i]) == 0){
                n.insert(nums[i]);
            }
            else{
                n.erase(nums[i]);
            }
        }
    vector<int> ans(n.begin(), n.end());
    return ans[0];
        
    }
    
};
