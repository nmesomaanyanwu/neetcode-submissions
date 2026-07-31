class MedianFinder {
    vector<int> values;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        values.push_back(num);
        
    }
    
    double findMedian() {
        if (!values.empty()){
            sort(values.begin(), values.end());

            if (values.size() % 2 == 0){
                int indexa = (values.size()/2);
                int indexb = indexa - 1;
                double ans = (values[indexa]+ values[indexb]) / 2.0;
                return ans;

            }
            else{
                int index = (values.size()/ 2);
                double cur = static_cast<double>(values[index]);
                return cur;
            }
        }
        else{
            return 0.0;
        }
        
    }
};
