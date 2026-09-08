class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_count = nums[0]; // this is the current minimum 
        int current = nums[0]; // start with the first integer -2 

        for (int right = 1 ; right < nums.size() ; right++){
            current = max(nums[right] , current + nums[right]);
            max_count = max(max_count , current);
        }

        return max_count;
    }
};
