class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search for possible row;
        int row = -1;
        int l = 0;
        int r = matrix.size() - 1;
        while(l<r){
            int mid = l+(r-l)/2;
            int midd = matrix[mid][0];
            if(midd==target) {return true;}
            if(midd<target) l = mid+1;
            else{r = mid;}
        }
        row = l;
        // Critical check on rows: MAinly for the case when l=0; because that is when row can go out of bound.
        if(matrix[row][0]>target) row = row -1;
        if(row<0) return false;
        
        // search in the row itself
        l=0;
        r=matrix[0].size()-1;
        while(l<r){
            int mid = l +(r-l)/2;
            int val = matrix[row][mid];
            if(val==target) return true;
            else if(val<target) l = mid+1;
            else {r = mid;}
        }
        if(matrix[row][l]==target)return true;
        return false;
    }
};
