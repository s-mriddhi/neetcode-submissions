class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()||num<left.top()){
            left.push(num);
            if(left.size()-1>right.size()){
                right.push(left.top());
                left.pop();
            }
        }
        else{
            right.push(num);
            if(right.size()>left.size()){
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if((left.size()+right.size())%2==1){
            return left.top();
        }
        return (left.top()+right.top())/2.0;
    }
};
