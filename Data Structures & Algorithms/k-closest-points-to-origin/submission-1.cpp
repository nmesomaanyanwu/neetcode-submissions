class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;  
        struct Compare{
            bool operator()(const vector<int>& a ,const vector<int>& b ) const{
            int distancea = a[0] * a[0] + a[1] * a[1];
            int distanceb = b[0] * b[0] + b[1] * b[1];

            return distancea > distanceb;
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq; // compare based on distance close to the  origin 
        
        for (auto& point : points){
            pq.push(point);
        }

        for (int n = 0 ; n < k; n++){
            vector<int> path = pq.top();
            pq.pop();
            ans.push_back(path);
        } 

        return ans;
    }
};
