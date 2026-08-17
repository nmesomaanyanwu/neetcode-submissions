class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 0;

        for (int i = 0 ; i < n ; i++){
            if (i % 2 == 0){
                even += nums[i];
            }
            else{
                odd += nums[i];
            }
        }

        return max(even , odd);
        
    }
};
