class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*what to do :
        1) we use a max heap 
        2) we take the two biggest if they are equal we pop them 
        3) if y > x we remove x and push (y - x)
        4) if stone == 1 or less return that stone 
        */
        priority_queue<int> weight;

        for(int i = 0 ; i < stones.size(); i++){
            weight.push(stones[i]);
        } 

        // loop for crushing
        while (weight.size() != 0){
            if (weight.size() <= 1){
                return weight.top();
            }
            int a = weight.top();
            weight.pop();

            int b = weight.top();
            weight.pop();

            if (a == b){
                continue;
            }
            if (a > b){
                weight.push(a-b);
            }  
        
    }
    return weight.size();

    }
};
