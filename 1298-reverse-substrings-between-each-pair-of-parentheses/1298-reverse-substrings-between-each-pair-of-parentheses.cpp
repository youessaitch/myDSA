class Solution {
public:
    int n;
    string reverseParentheses(string s) {
        n = s.size();
        string temp = "";
        stack<string> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){ 
                st.push(temp);
                cout<<st.top()<<" ";
                temp="";
                continue;
            }
            if(s[i]==')'){
                reverse(temp.begin(),temp.end());
                temp = st.top() + temp;
                st.pop();
                continue;
            }
            temp += s[i];
        }
        return temp;
    }
};