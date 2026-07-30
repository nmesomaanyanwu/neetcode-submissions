#include <sstream>
class Solution {
unordered_map<string, vector<string>> m {
    {"2" , {"a" , "b" , "c"}},
    {"3" , {"d" , "e" , "f"}},
    {"4" , {"g" , "h" , "i"}},
    {"5" , {"j" , "k", "l"}},
    {"6" , {"m" , "n" , "o"}},
    {"7" , {"p" , "q" , "r", "s"}},
    {"8" , {"t", "u" , "v"}},
    {"9" , {"w", "x", "y", "z"}},
};
vector<string> ans;
string path = ""; 
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
        backtrack(0,digits);
        return ans;
        
    }

private:
    
    void backtrack(int index, string& digits){
        if (index == digits.size()){
            ans.push_back(path); 
            return;
        }
        // get the index
          
        string d(1, digits[index]);
    

        for (const string& ch : m[d]){
            path += ch;
            backtrack(index + 1 , digits);
            path.pop_back();
        }


     }
        

};
