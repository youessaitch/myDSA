class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int cnt = 0;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                auto t = st.top();
                if((v[i][0] >= t.first) && (v[i][0] < t.second)){
                    cnt++;
                    if (v[i][1] < t.second) {
                        st.pop();  // Remove the previous interval (t) as it overlaps with v[i]
                        st.push({v[i][0], v[i][1]});
                    }
                }else{
                    st.push({v[i][0],v[i][1]});
                }
            }else{
                st.push({v[i][0],v[i][1]});
            }
            
        }

        return cnt;
    }
};