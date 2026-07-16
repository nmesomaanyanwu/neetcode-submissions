class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l = 0;

        for (int i = 0; i < matrix.size(); i++){
            int r = matrix[i].size() - 1 ;
            if ((matrix[i][l] <= target) && (target <= matrix[i][r])){
                vector<int> n = matrix[i];
                while (l <= r){
                    int mid = (l + r) / 2;

                    if (n[mid] == target){
                        return true;

                    }
                    else if (n[mid] < target){
                        l = mid + 1;
                    }
                    else if (n[mid] > target){
                        r = mid - 1;
                    }
                }

            }
        }


        return false;

    }
};
