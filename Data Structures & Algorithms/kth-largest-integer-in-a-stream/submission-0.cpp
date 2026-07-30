class KthLargest {
int k ; // this is the member variable that we will be using to pass into the object 
priority_queue<int , vector<int>, greater<int>> pq; // because its the global thing that every cal will need 
public:
/*
We want to firstly set our heap we can use a min heap that has k elements exactly so the top element is the smalles if add and it passes we need to remve the top element 
*/
    KthLargest(int k, vector<int>& nums):k(k) {
        for (auto& num: nums){
            add(num);
        }
        
    }
    
    int add(int val) {

        pq.push(val);

        if(pq.size() > k){
            pq.pop();
        } 
        
        return pq.top();   
    }
};
