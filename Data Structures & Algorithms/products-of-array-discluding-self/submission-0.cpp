class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefixPro(n);
        vector <int> suffixPro(n);
        prefixPro[0] = 1;
        suffixPro[n-1] = 1;
        for(int i =1; i<n; i++){
            prefixPro[i] = prefixPro[i-1]*nums[i-1];
        }
        for( int j = n-2; j>=0; j--){
            suffixPro[j]= nums[j+1]*suffixPro[j+1];
        }
        vector <int> output(n);
        for(int i = 0; i<n; i++){
            output[i] = prefixPro[i] * suffixPro[i];
        }
        return output;
    }
};
