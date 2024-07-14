class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //2 3 -1 -1
        int n = nums2.size();
        vector<int> v(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(!st.empty() && st.top()>nums2[i]) v[i] = st.top();
            st.push(nums2[i]); 
        }

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums2[i]] = v[i];
        }

        vector<int> ans;
        for(auto it: nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};