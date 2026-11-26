class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
       
        for (auto cur : nums){
            a = a ^ cur;
        };

        return a;
        
    }
};
