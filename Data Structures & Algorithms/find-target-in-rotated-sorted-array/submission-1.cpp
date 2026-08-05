class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while ( l <= r){

            int mid = (l + r) / 2;
            if (nums[mid] == target){
                return mid;
            }

            // check if left side 
            if (nums[l] <= nums[mid]){
                //check if its in the left 
                if (nums[l] <= target && target < nums[mid]){
                    r = mid - 1; 
                }else{
                    l = mid + 1 ;
                }
            }
            else{// check right 

                if (nums[mid] < target && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1 ;
                }

            }
        }

        return -1;
        
    }
};
