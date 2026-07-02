class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int mx_area = 0;
        stack<pair<int, int>> st; // index, height
        for(int i=0; i<n; i++){
            int last_ind= i; // dont initialize with rush.
            while(!st.empty() && heights[i]<st.top().second){
                last_ind = st.top().first;
                int area = (i-last_ind)*st.top().second;
                mx_area = max(mx_area, area);
                st.pop();
            }
            st.push({last_ind , heights[i]});
        }
        
        while(st.empty()==0){
            int index = st.top().first;
            int height = st.top().second;
            int area = (heights.size()-index)* height;
            mx_area = max(mx_area , area);
            st.pop();
        }

        return mx_area;
    }
};
