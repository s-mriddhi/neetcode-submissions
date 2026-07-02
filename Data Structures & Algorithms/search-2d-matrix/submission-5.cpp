class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int l= 0;
        int r= ROWS * COLS - 1;
        while(l<r){
            int mid = l + (r-l)/2;
            int row = mid/COLS;
            int col = mid%COLS;
            int val = matrix[row][col];
            if(val==target) return true;
            else if(val<target) l = mid + 1;
            else {
                r = mid;
            }
        }
        if(matrix[l/COLS][l%COLS]==target) return true;
        return false;
    }
};
