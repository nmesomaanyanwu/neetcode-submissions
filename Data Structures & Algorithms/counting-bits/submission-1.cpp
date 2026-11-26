class Solution {
public:
    vector<int> countBits(int n) {
        // there is a dp pattern so we start with 1 as the offset each time we encounter the offset x 2 equal current no we update the offset . The dp pattern is going to be dp[i] = 1 + dp[i - offset]. were offset is a power of 2 

    int s = n+1;
    vector<int> result(s);
    if (n>=0){
        result[0] = 0;
    }
    int offset = 1;

    for (int i = 1 ; i <= n ; i++){
        if (i == offset * 2){
            offset = i;
        }
        result[i] = 1 + result[i-offset];

    }

    return result;
    }
    
};
