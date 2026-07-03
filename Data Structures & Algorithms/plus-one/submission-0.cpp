class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int i = digits.size()-1;
        int car =1;
        while(i>=0 || car){
            int dig =0;
            if(i>=0){
                dig = digits[i];
            }
            int sum = car + dig;
            car = sum/10;
            res.push_back(sum%10);
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
