class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*
        firstly nmake a stack 
        1. if string is a num then add to stack 
        2. if we get an operator then we pop the two previous values and do the operator and return to stack 
        3. We contine to do this until all values are done 
        4.We return our final value in the stack
        */

        stack<int> val={};

        for (auto& token: tokens){
            if(token == "+" || token == "-" || token == "/" || token == "*"){
                int b = val.top();
                val.pop();
                int a = val.top();
                val.pop();

                if (token == "+"){
                    val.push(a+b);
                }
                else if (token == "-"){
                    val.push(a-b);
                }
                else if (token == "/"){
                    val.push(a/b);
                }
                else if (token == "*"){
                    val.push(a*b);
                }
            }
            else{
                val.push(stoi(token));
            }


        }

        return val.top();

    }
    
        
    

};
