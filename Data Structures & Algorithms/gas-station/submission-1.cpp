class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        for(int i = 0; i<gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_gas<total_cost) return -1;
        // From this section onwards, we are sure that answer exists!
        int total = 0;
        int res = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                res = i+1;
            }
        }

        return res;
    }
};
