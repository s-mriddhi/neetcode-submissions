class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Always binary search on the smaller array to prevent out-of-bound errors
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int k = (n1 + n2) / 2;
        int low = max(0, k - n2);
        int high = k;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if (mid > 0) 
                l1 = nums1[mid - 1];
            if (k - mid > 0) {
                l2 = nums2[k - mid - 1];
            }
            if (mid < n1) {
                r1 = nums1[mid];
            }
            if (k - mid < n2) {
                r2 = nums2[k - mid];
            }
            
            // Your exact logic completed here:
            // If l2 <= r1, our current mid partition is valid or we might need to look right
            if (l2 <= r1) {
                high = mid; 
            } else {
                low = mid + 1;
            }
        }
        
        // After loop finishes, low == high (this is the correct partition index)
        int mid = low;
        int l1 = (mid > 0) ? nums1[mid - 1] : INT_MIN;
        int l2 = (k - mid > 0) ? nums2[k - mid - 1] : INT_MIN;
        int r1 = (mid < n1) ? nums1[mid] : INT_MAX;
        int r2 = (k - mid < n2) ? nums2[k - mid] : INT_MAX;
        
        // Calculate the median based on total length
        if ((n1 + n2) % 2 == 1) {
            return min(r1, r2);
        } else {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
    }
};
