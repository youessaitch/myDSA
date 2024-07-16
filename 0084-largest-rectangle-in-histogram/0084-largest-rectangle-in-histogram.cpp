class Solution {
public:
    int n;
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        vector<int> prev(n,-1); //next smallest 
        vector<int> next(n,n); //next smallest 
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty() && heights[st.top()] < heights[i]) prev[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty() && heights[st.top()] < heights[i]) next[i] = st.top();
            st.push(i);
        }

        // int ans = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            int area = (abs(i-prev[i])+abs(i-next[i])-1)*heights[i];
            maxi = max(maxi,area);
        }
        return maxi;
    }
};