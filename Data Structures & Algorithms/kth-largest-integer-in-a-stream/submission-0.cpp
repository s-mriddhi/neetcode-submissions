class KthLargest {
private:
    priority_queue <int , vector<int> , greater<int>> pq;
    int capacity ;
public:
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for(auto num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(pq.size()<capacity){
            pq.push(val);
        }
        else{
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
