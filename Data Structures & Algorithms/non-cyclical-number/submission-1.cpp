class Solution {
public:
    int sumOfSq(int m){
        int ans =0;
        while(m>0){
            int dig = m%10;
            ans += dig*dig;
            m = m/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSq(n);
        while(fast!=1){
            slow = sumOfSq(slow);
            fast = sumOfSq(sumOfSq(fast));
            if(fast==slow){
                break;
            }
        }
        return fast==1;
        //Slow fast pointer , very good use
    }
};
