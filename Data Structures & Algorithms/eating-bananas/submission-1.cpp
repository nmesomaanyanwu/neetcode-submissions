class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        /*Ok like so for this:
        1. We have like we have to find the maximum in the pile and difine min count to be Int_Max 
        2. when we have the maximum  then we check if it can eat all the nums in less than h hours if that possible 
        3.then we continue to check until the  the rate cant fit the hours
        4. we check if int_max has changed if not return 0
        
        */
        
        int r = *max_element(piles.begin(), piles.end());
        int min_rate = r;
        int l = 1 ;

        while (l <=r ){
            int count = 0;
            int mid = l + (r - l)/ 2;

            for (int i = 0 ; i < piles.size(); i++){
                if (piles[i] <= mid){
                    count+= 1;
                }
                else{
                    if (piles[i] % mid == 0 ){
                    count += piles[i]/ mid ;
                    }
                    else{
                         count += (piles[i]/ mid) + 1 ;
                    }
                }
            }
            
            if (count <= h){
                r = mid - 1;
                min_rate = min(min_rate ,mid);
            }
            else{
                l = mid + 1;

            }
            

        }
        

        return min_rate;
        
    }
};
