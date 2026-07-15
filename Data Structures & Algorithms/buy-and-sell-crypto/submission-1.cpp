class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int max_count = 0;


        for (int right = 1 ; right < prices.size(); right++){

            while (prices[left] > prices[right]){
                left++;
            }
            int count = prices[right] - prices[left];
            max_count = max(max_count , count);
        }

        return max_count;
        
    }
};
