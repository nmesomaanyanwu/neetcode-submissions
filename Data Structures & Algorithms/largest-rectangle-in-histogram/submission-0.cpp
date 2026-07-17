class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        Largest Rectangle in Histogram
        1. okay we will have a stack that contains pairs of both index and height 
        2. we will keep track of our max area 
        3. we terate through the list each time we find a height less than the height on the stack we pop
        the height and get the index and height. we then check that height to see if its greater than the current max
        area by multiplying its height with the difference between the current index index and that heights index 
        4. then we update the index of our new one to go to the one we popped because it can go through it so its becomes that index
        5. Then when were done popping values that cant continue we will have values in our stack that were able to reach the end 
        6. We iterate through those values and find if any of them could produce a max rea we return our max area 
        */

        int maxArea = 0;
        stack<pair<int,int>> st;  // this contains the index and height 
        int n = heights.size();


        for (int i = 0 ; i < heights.size(); i++){
            int h = heights[i];
            int start = i;

            while (!st.empty() && (st.top().second > h)){
                // this means thats the furthest st.top() could go and that we need to find the area that could have made
                maxArea = max(maxArea , (st.top().second  * (i - st.top().first)));
                start = st.top().first;
                st.pop();
            }
            st.push(make_pair(start , h));
        }
        
        // these are for the heights that reached the end 
    
        while (!st.empty()){
            auto& [index , height] = st.top();
            st.pop();
            maxArea = max(maxArea , height * (n- index));
        }

        return maxArea;
    }
};
