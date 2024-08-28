#define pii pair<int,int>

class Solution {
public:
    void eraseInBetween(int l, int r, set<int> &st){
        auto it_start = st.lower_bound(l);
        auto it_end = st.upper_bound(r);
        st.erase(it_start, it_end);
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        set<int> st;
        for(int i=0;i<n;i++) st.insert(i);

        vector<int> ans;

        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            eraseInBetween(u+1,v-1,st);
            ans.push_back(st.size()-1);
        }

        return ans;
    }
};