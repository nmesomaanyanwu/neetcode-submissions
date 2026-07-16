class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
        We have two vectors : position and speed 
        1)so firstly we will create a pair  in vectors which tie the position to the speed
        2) then we create sort it in ascendng order
        3) We will iterate backwards from it and check for the stack if not empty whether its time to reach is less than the previous 
        4) if  yes we then add it to the stach at the same time to reach 
        5) we at the end find out all the different values 
        */

        int n = position.size();
        vector<pair<int,int>> cars;
        stack<float> st;  // this will contain the values of time_to_reach 

        for (int i = 0 ; i < n ; i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(), cars.end());

        for (int j = cars.size()-1; j >= 0 ; j--){
            float time_to_reach = (target - cars[j].first) / (float)cars[j].second;
            if (!st.empty() && (time_to_reach <= st.top())){
                continue;
            }else{
                st.push(time_to_reach);
            }
        }


        return st.size();


        
    }
};
