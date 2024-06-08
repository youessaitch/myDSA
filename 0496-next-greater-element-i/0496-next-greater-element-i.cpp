class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nge(m);
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            if(st.empty()){
                nge[i]=-1;
                st.push(nums2[i]);
                continue;
            }
            if(!st.empty()){
                if(st.top()>nums2[i]){
                    nge[i]=st.top();
                    st.push(nums2[i]);
                }else{
                    bool emp = 0;
                    while(nums2[i]>st.top()){
                        st.pop();
                        if(st.empty()){
                            emp =1;
                            break;
                        }
                    }

                    if(emp){
                        nge[i] = -1;
                        st.push(nums2[i]);
                    }else{
                        nge[i] = st.top();
                        st.push(nums2[i]);
                    }

                }
            }
        }

        unordered_map<int,int> mpp;
        for(int i=0;i<m;i++){
            mpp[nums2[i]] = nge[i];
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};