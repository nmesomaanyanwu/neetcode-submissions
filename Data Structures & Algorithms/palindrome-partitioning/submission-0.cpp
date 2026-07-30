class Solution {
vector<vector<string>> ans;
vector<string> path;

public:
    vector<vector<string>> partition(string s) {
        // at each recursive level your checking if its a valid palindrome 
        backtrack(0,s);
        return ans;
        
    }

private:
    void backtrack(int left, string& s){
        if (left == s.size()){
            ans.push_back(path);
            return;
        }

        for( int right = left ; right < s.size(); right++){
            // if a valid palindrome 
            if (palindrome(left , right, s)){
                path.push_back(s.substr(left,right - left + 1)); 
                backtrack(right + 1, s);
                path.pop_back();
            } 
            
        } 


    }   

    bool palindrome(int left , int right ,string& s){
        while (left < right){
            if (s[left] != s[right]){
                return false;
            }
            right--;
            left++;
        }

        return true;
    }
};
