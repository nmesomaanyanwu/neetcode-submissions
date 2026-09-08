class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 1){
            return nums[0];
        }

        int max_count = INT_MIN; // this is the current minimum 

        int left = 0;
        int current = 0 ;

        for (int right = 0 ; right < nums.size() ; right++){
            current += nums[right]; // add a number

            while (current < 0){
                current -= nums[left];
                left++;
            }

            max_count = max(max_count , current);
        }

        return max_count;
    }
};
