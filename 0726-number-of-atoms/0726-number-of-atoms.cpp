class Solution {
public:
    int n;
    string countOfAtoms(string formula) {
        n = formula.size();
        // unordered_map<string,int> mpp;
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }else if(formula[i]==')'){
                auto mpp = st.top();
                st.pop();
                i++;

                string multi = "";
                while(i<n && isdigit(formula[i])){
                    multi += formula[i];
                    i++;
                }

                if(multi.size()>0){
                    int multiple = stoi(multi);
                    for(auto &it: mpp){
                        it.second*=multiple;
                    }
                }

                //lets merge to the stack top element
                for(auto &it: mpp){
                    string ele = it.first;
                    int cnt = it.second;
                    st.top()[ele] += cnt;
                }

            }else{
                string currEle = "";
                string num = "";
                currEle += formula[i];
                i++;

                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currEle += formula[i];
                    i++;
                }

                while(i<n && isdigit(formula[i])){
                    num+=formula[i];
                    i++;
                }
                int digi = 0;
                if(num.size()==0) digi=1;
                else digi = stoi(num);

                st.top()[currEle] += digi;

            }
        }

        map<string,int> SortedMap(st.top().begin(),st.top().end());
        string ans = "";
        for(auto it: SortedMap){
            ans+=it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};