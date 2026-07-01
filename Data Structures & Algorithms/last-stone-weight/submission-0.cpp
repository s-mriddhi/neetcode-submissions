class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int wt : stones){
            pq.push(wt);
        }
        while(pq.empty()!=1){
            if(pq.size()==1)return pq.top();
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top1>top2){
                pq.push(top1-top2);
            }
        }

        return 0;
    }
};
