class MedianFinder {
    priority_queue<int> left ; // left stores the smaller elements returns the top
    priority_queue<int , vector<int>, greater<>> right; // stores the larger elements  returning the smallest of them
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || num < left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        // repositioning elements 
        while (left.size() > right.size()+ 1){
            int a = left.top();
            left.pop();
            right.push(a);
        }

        while (left.size()+ 1 < right.size()){
            int a = right.top();
            right.pop();
            left.push(a);
        }
        
    }
    
    double findMedian() {
        if (left.empty() && right.empty()){
            return 0.0;
        }
        if (left.size()== right.size()){
            int a = left.top();
            int b = right.top();

            double ans = (a + b)/2.0;
            return ans;
        }
        else if (left.size()+ 1 == right.size()){
            return static_cast<double>(right.top());
        }
        else{
            return static_cast<double>(left.top());
        }

        
    }
};
