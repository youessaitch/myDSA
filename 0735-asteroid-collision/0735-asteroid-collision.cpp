class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size();
        int i=0;
        stack<int> st;

        while(i<n){
            if(st.empty()) st.push(v[i]);
            else{
                int curr = v[i];
                bool destroy = false; // current destroyed or not
                
                while(!st.empty() && st.top()>0 && curr<0){
                    auto top = st.top();
                    // st.pop();
                    if(abs(top) == abs(curr)){
                        st.pop();
                        destroy = true;
                        break;
                    }
                    if(abs(top)<abs(curr)){
                        st.pop();
                    }else if(abs(top)>abs(curr)){
                        destroy = true;
                        break;
                    }
                }
                
                if(!destroy) st.push(curr);
            }   
            i++;
        }

        vector<int> ans;
        while(!st.empty()){
            auto it = st.top();
            ans.push_back(it);
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};