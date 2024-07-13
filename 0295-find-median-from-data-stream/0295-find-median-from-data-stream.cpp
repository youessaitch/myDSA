class MedianFinder {
public:

    priority_queue<double> left_maxHeap;
    priority_queue<double,vector<double>,greater<double>> right_minHeap;

    MedianFinder() {
        // vector<double> ans;
    }
    
    void addNum(int num) {
        if(!left_maxHeap.empty()){
            if(num > left_maxHeap.top()){
                right_minHeap.push(num);
            }else{
                left_maxHeap.push(num);
            }

            if(left_maxHeap.size() > right_minHeap.size() + 1){
                right_minHeap.push(left_maxHeap.top());
                left_maxHeap.pop();
            } else if(right_minHeap.size() > left_maxHeap.size()){
                left_maxHeap.push(right_minHeap.top());
                right_minHeap.pop();
            }
        }

        if(left_maxHeap.empty()){
            left_maxHeap.push(num);
        }
    }
    
    double findMedian() {
        int size = left_maxHeap.size() + right_minHeap.size();
        if(size%2 == 0){
            double ans = (left_maxHeap.top() + right_minHeap.top())/2.0;
            return ans;
        }
        double ans = left_maxHeap.top();
        return ans; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */