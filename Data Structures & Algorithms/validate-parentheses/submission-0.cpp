class Solution {
public:
    bool isValid(string s) {
        /*
        ill make an undodered map that maps closing brackets to its oppening brackets
        i will iterate over the list and if i get to a closing bracket
        then i will check if my stack isnt empty and if the last element is equal to the maping in the hashmap then pop
        if not then ill return false 
        if ive checked every character and te stack is still not empty i'll return false;

        */

        stack<char> st;
        unordered_map<char , int> pairs= {{')', '('}, {'}', '{'}, {']','['}};

        for(int i = 0; i < s.size(); i++ ){
            if (pairs.find(s[i]) == pairs.end()){
                st.push(s[i]);
            }
            else {
                if (!st.empty() && (st.top() == pairs[s[i]])){
                    st.pop();
                }else{
                    return false;
                }
            }


            }
            if (st.empty()){
                return true;
            }else{
                return false;
        }

    }
        
};
