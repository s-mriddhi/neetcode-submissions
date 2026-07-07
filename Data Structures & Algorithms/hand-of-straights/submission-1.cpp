class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map <int, int> mp;
        for(int num: hand){
            mp[num]++;
        }
        for(auto num : hand){ 
            int start = num; 
            while(mp[start-1]>0) start = start - 1;
            while(start <= num){
                while(mp[start]){
                int smallest  = start;
                for(int i = 0; i< groupSize; i++){
                    int curr = smallest + i;
                    if(mp[curr]==0) return false;
                    mp[curr]--;
                }
            }
            start += start + 1;
            }
        }
    return true;
    }
};
// Try out the n solution as well
/*
1: 1
2: 2
3: 2
4: 2
5: 1
*/
/*
1: 0
2: 0
3: 1
4: 0
5: 1
6: 1 
7: 1
*/
// We can maintain a pointer to first non-zero index during our seep itself.
// This ensures eevry element is visited at once and we get our solution in O(N)