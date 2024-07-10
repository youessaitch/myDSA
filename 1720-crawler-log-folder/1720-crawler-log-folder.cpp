class Solution {
public:
    int n;
    int minOperations(vector<string>& logs) {
        n = logs.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(st.empty()) continue;
                else{ 
                    st.pop();
                    continue;
                    }
            }

            if(logs[i]=="./") continue;

            st.push(logs[i]);
        }
        return st.size();
    }
};