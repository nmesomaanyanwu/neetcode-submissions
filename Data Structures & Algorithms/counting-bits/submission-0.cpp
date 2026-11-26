class Solution {
public:
    #define LEN 16
    vector<int> countBits(int n) {
        // ill make a array of size n
        // ill iterate through each number from 0 to n 
        // ill use the 16 unsigned bits we need to like check for each bit if its a 1 and then ill return the  count 

        vector<int> result(n+1);

        for (int i = 0 ; i <= n ; i++){
            int count = 0;
            uint16_t cur = (uint16_t)i;

            for (int j = 0 ; j < 16 ; j++){
                if ((cur & (1 << j)) != 0){
                    count += 1;
                }
            }
            result[i] = count; 

        }

        return result;
    }
};
