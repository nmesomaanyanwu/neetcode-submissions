class Solution {
vector<string> ans;
string path = "";
unordered_map<char, char> p= {{')', '('}};
stack<char> seen; 
public:
    vector<string> generateParenthesis(int n) {
        /*
        1. we need to generate all the posible parentheses given n
        2. we backtrack on what could be creted its either we close tahta parentheses or add a new one
        3.we return if stack empty and char size is equal to n x2 
        
        */
        int open = 0;
        int close = 0;
        backtrack(open , close , n);
        return ans;
    }
private:

    void backtrack(int open ,int close, int n){
        // when is a string valid 
        if (open == n &&  open == close){
            ans.push_back(path);
        }

        if (open < n){
            path.push_back('(');
            open++;
            backtrack(open , close , n);
            path.pop_back();
            open--;

        }

        if (open > 0 && (close< open) ){
            path.push_back(')');
            close++;
            backtrack(open , close , n);
            path.pop_back();
            close--;

        }

        
    }

};
