class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while (x != 0) {
            // 1. Pop the last digit from x
            int pop = x % 10;
            x /= 10;
            
            // 2. Positive Overflow Check (Before multiplying by 10)
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) {
                return 0; 
            }
            
            // 3. Negative Overflow Check (Before multiplying by 10)
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            // 4. If safe, update the reversed result
            res = res * 10 + pop;
        }
        
        return res;
    }
};