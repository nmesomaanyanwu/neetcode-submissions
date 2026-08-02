class Solution {
public:
    int climbStairs(int n) {
        
     return dfs(n, 0);
        
    }

private:
 int  dfs(int n , int count){
    if (count == n){
        return 1;
    }
    if (count > n){
        return 0;
    }
   
    
    int takeOne = dfs(n , count + 1);
    int takeTwo = dfs(n , count + 2 );
     

    return takeOne + takeTwo;
 }
    
};
