class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n-1];
        int l = 0;
        int r = n-1;
        int res = 0;
        while( l < r){
            if(leftMax > rightMax){
                r--;
                if( height[r] > rightMax){
                    rightMax = height[r];
                }
                res += rightMax - height[r];
            }
            else {
                 l++;
                if(height[l] > leftMax){
                    leftMax = height[l];
                }
                res += leftMax - height[l];
            }
        }
        return res;
    }
};
