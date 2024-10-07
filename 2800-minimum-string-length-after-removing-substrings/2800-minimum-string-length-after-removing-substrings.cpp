class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.size();

        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=2){
                int upr = st.top();
                st.pop();
                int nic = st.top();
                st.pop();
                if((nic == 'A' && upr == 'B') || (nic == 'C' && upr == 'D')){
                    continue;
                }else{
                    st.push(nic);
                    st.push(upr);
                }
            }
        }

        return st.size();
    }
};