class Solution {
private:
    bool check(int i, vector<int>& gas, vector<int>& cost){
        int mod = gas.size();
        int start = i;
        int cur = 0;
        while((i+1)%mod!=start){ 
            cur += gas[i];
            if(cur < cost[i]) return false;
            cur = cur - cost[i]; 
            i = (i+1)%mod; // we are able to point i to the last station
       }
        // check for last to start station
        cur += gas[i];
        return (cur >= cost[i]);
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            if(check(i, gas, cost)) return i;
        }
        return -1;
    }
};
