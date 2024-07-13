class Solution {
public:
    int n;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        n = positions.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({positions[i],healths[i],directions[i],i});
        }
        sort(v.begin(),v.end());
        // for(auto it: v){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        stack<vector<int>> st; //{directions, health,i}

        for(auto it: v){
            int khun = it[1];
            auto dir = it[2];
            auto idx = it[3];
            if(st.empty() || dir == 'R' || st.top()[0] == 'L'){
                st.push({dir,khun,idx});
                continue;
            }
            if(dir == 'L'){
                bool ch = false;
                while(!st.empty() && st.top()[0]== 'R' && !ch){
                    auto top = st.top();
                    auto topDir = top[0];
                    auto topKhun = top[1];
                    auto topIdx = top[2];
                
                    if(khun < topKhun){
                        st.pop();
                        topKhun-=1;
                        st.push({topDir,topKhun,topIdx});
                        ch = true;
                        // break;
                    }else if(khun > topKhun){
                        st.pop();
                        khun-=1;
                    }else{
                        st.pop();
                        ch = true;
                        // break;
                    }
                }
                if(ch) continue;
                st.push({dir,khun,idx});
            }
            
        }
        int direc = 0;
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back({st.top()[2],st.top()[1]});
            st.pop();
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for(auto it: ans){
            res.push_back(it[1]);
        }
        return res;
    }
};