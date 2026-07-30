class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using item = pair<int , int>;

        vector<vector<int>> ans;  
        struct Compare{
            bool operator()(const item& a ,const item& b ) const{
            int distancea = a.first * a.first + a.second * a.second;
            int distanceb = b.first * b.first + b.second * b.second;

            return distancea > distanceb;
            }
        };

        priority_queue<item, vector<item>, Compare> pq; // compare based on distance close to the  origin 
        
        for (auto& point : points){
            int a = point[0];
            int b = point[1];
            pq.push({a,b});
        }

        for (int n = 0 ; n < k; n++){
            item path = pq.top();
            pq.pop();
            ans.push_back({path.first , path.second});
        } 

        return ans;
    }
};
