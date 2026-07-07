class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x = 1/x;
            n = n * -1;
        }
        double res = 1;
       while(n > 0){
         if(n%2!=0){
            res = res * x;
        }
        n = n/2;
        x = x * x;
       }
        return res;
    }
};
