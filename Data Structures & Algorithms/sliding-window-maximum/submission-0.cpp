class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        ok we can solve this question in both
        o(n.k) and o(n). Ill do o(n)

        so , firstly :
        1. lets say we store the indices in a dequeue
        2. The reason were storing it in a deque is that when we iterate through it
        3. if theres a deque we check if this new index is higher than the previous index thats there 
        4. if that is higher we pop it because if we have a new highesst valu 
        5. then if the window has shifted and the l pointer is outside the window we leave it 
        */


        int l = 0 ; 
        deque<int> q;
        vector<int> res;

        for (int r = 0 ; r < nums.size(); r++){

            while( !q.empty() && (nums[q.back()] < nums[r])){
                    q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()){
                q.pop_front();
            }

            if ((r + 1) >= k){
                res.push_back(nums[q.front()]);
                l++;

            }


        }

        return res;
    }


};
