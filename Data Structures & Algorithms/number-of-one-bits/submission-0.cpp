class Solution {
public:
    #define LEN 32
    int hammingWeight(uint32_t n) {
        // i feel like we could figure out the size of like 23 represented as a bit and then iterate through it with a 1 and do and and at each position using shift left logical if its equal to  1 then we add it to our count , actual since where using uint32_t we coult use the constant 32 to iterate through each position our time complexity should be about 0(32) 0(1)space

        int count = 0;
        
        for (int i = 0 ; i < LEN; i++){
            if ((n & (1 << i))!= 0){
                count += 1;
            }
        }

        return count;

    }
};
