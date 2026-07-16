class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        /*
        How i will approach this problem:
        1)Ok we make a stack and also we have a result vector thats the size of temperatures 
        2)we have a for loop and check at each teration if this is greater than whats in the stack if yes we
        3) find the difference between the indexes and pop if and then add it to the stack 
        4) We continue doing this until everything is popped off or just return 0 
    
        */
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n, 0);

        for (int i = 0 ; i < n ; i++){

            while(!st.empty() && (temperatures[i] > temperatures[st.top()])){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
   
    }
};
