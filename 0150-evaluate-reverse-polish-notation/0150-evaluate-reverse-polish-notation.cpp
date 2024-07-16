class Solution {
public:
    int n;
    int evalRPN(vector<string>& tokens) {
        n = tokens.size();
        stack<int> st;
        for (auto it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (it == "+") st.push(num1 + num2);
                if (it == "-") st.push(num1 - num2);
                if (it == "*") st.push(num1 * num2);
                if (it == "/") st.push(num1 / num2);
            } else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }

};