class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.size()==0){
                st.push(s[i]);
                continue;
            }

            if(st.top() == '(' && s[i] == ')'){
                st.pop();
            }else if(st.top() == '[' && s[i] == ']'){
                st.pop();
            }else if(st.top() == '{' && s[i] == '}'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        if(st.size()==0) return 1;
        return 0;
    }
};