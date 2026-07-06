class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map <int, int> mp;
        for(int num: hand){
            mp[num]++;
        }
        if(hand.size()%groupSize != 0)return false;
        for(auto it = mp.begin(); it != mp.end(); it++){
            auto k = it->second;
            if(k>0){
                int small_card = it->first;
                for(int i = 0; i<groupSize; i++){
                    int cur_card = small_card + i;
                    if(mp[cur_card]<k) return false;
                    mp[cur_card] -= k;
                }
            }
        }
        return true;
    }
};
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