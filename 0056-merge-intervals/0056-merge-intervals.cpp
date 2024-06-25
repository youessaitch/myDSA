class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                auto t = st.top();
                if((v[i][0] >= t.first) && (v[i][0] <= t.second)){
                    st.pop();
                    st.push({min(v[i][0],t.first),max(v[i][1],t.second)});
                }else{
                    st.push({v[i][0],v[i][1]});
                }
            }else{
                st.push({v[i][0],v[i][1]});
            }
            
        }
        while(!st.empty()){
            ans.push_back({st.top().first, st.top().second});
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};