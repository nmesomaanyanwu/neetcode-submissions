class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()){
            return 0;
        }

        vector<int> skip(n,0);
        vector<int> take(n ,0);
        take[0] = nums[0];

        for (int i = 1 ; i < n ; i++){
            skip[i] = max(skip[i-1], take[i-1]);
            take[i] = nums[i] + skip[i-1];
        }

        return max(take.back(), skip.back());
        
    }
};
