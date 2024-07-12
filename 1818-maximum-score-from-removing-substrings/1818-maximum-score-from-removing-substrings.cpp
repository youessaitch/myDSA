class Solution {
public:
    int n;
    int maximumGain(string s, int x, int y) {
        n = s.size();
        stack<char> st;
        int cnt1 = 0;
        int cnt2 = 0;
        int ans = 0;

        if(x>y){
            for(int i=0;i<s.size();i++){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                if(s[i] == 'b'){
                    if(st.top()=='a'){
                        st.pop();
                        cnt1++;
                        continue;
                    }
                }
                st.push(s[i]);
            }

            s="";
            while(!st.empty()){
                s+=st.top();
                st.pop();
            } 
            reverse(s.begin(),s.end());
            for(int i=0;i<s.size();i++){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                if(s[i] == 'a'){
                    if(st.top()=='b'){
                        st.pop();
                        cnt2++;
                        continue;
                    }
                }
                st.push(s[i]);
            }
            cout<<cnt1<<" "<<cnt2;
            ans = cnt1*x + cnt2*y;
        }else{
            for(int i=0;i<s.size();i++){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                if(s[i] == 'a'){
                    if(st.top()=='b'){
                        st.pop();
                        cnt1++;
                        continue;
                    }
                }
                st.push(s[i]);
            }

            s="";
            while(!st.empty()){
                s+=st.top();
                st.pop();
            } 
            reverse(s.begin(),s.end());
            cout<<s<<endl;

            for(int i=0;i<s.size();i++){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                if(s[i] == 'b'){
                    if(st.top()=='a'){
                        st.pop();
                        cnt2++;
                        continue;
                    }
                }
                st.push(s[i]);
            }
            cout<<cnt1<<" "<<cnt2;
            ans = cnt1*y + cnt2*x;
        }
        return ans;

    }




    // int maximumGain(string s, int x, int y) {
    //     n = s.size();
    //     string ba = "ba";
    //     string ab = "ab";
    //     string copy = s;
    //     string temp = "";
    //     int ba_cnt=0,ab_cnt=0;

    //     if(x<y){
    //         while(1){
    //             n=copy.size();
    //             int cnt = 0;
    //             for(int i=0;i<n-1;i++){
    //                 if(copy.substr(i,2) == ba){
    //                     copy[i]='#';
    //                     copy[i+1]='#';
    //                     i++;
    //                     ba_cnt++;
    //                     cnt++;
    //                 }
    //             }
    //             if(cnt == 0) break;
    //             for(int i=0;i<copy.size();i++){
    //                 if(copy[i]!='#') temp+=copy[i];
    //             }
    //             copy="";
    //             copy += temp;
    //             temp="";
    //             // cout<<"copyba: "<<copy<<", ";
    //         }

    //         while(1){
    //             n=copy.size();
    //             int cnt = 0;
    //             for(int i=0;i<n-1;i++){
    //                 if(copy.substr(i,2) == ab){
    //                     copy[i]='#';
    //                     copy[i+1]='#';
    //                     i++;
    //                     ab_cnt++;
    //                     cnt++;
    //                 }
    //             }
    //             if(cnt == 0) break;
    //             for(int i=0;i<copy.size();i++){
    //                 if(copy[i]!='#') temp+=copy[i];
    //             }
    //             copy="";
    //             copy += temp;
    //             temp="";
    //         }
    //     }else{

    //         while(1){
    //             n=copy.size();
    //             int cnt = 0;
    //             for(int i=0;i<n-1;i++){
    //                 if(copy.substr(i,2) == ab){
    //                     copy[i]='#';
    //                     copy[i+1]='#';
    //                     i++;
    //                     ab_cnt++;
    //                     cnt++;
    //                 }
    //             }
    //             if(cnt == 0) break;
    //             for(int i=0;i<copy.size();i++){
    //                 if(copy[i]!='#') temp+=copy[i];
    //             }
    //             copy="";
    //             copy += temp;
    //             temp="";
    //         }

    //         while(1){
    //             n=copy.size();
    //             int cnt = 0;
    //             for(int i=0;i<n-1;i++){
    //                 if(copy.substr(i,2) == ba){
    //                     copy[i]='#';
    //                     copy[i+1]='#';
    //                     i++;
    //                     ba_cnt++;
    //                     cnt++;
    //                 }
    //             }
    //             if(cnt == 0) break;
    //             for(int i=0;i<copy.size();i++){
    //                 if(copy[i]!='#') temp+=copy[i];
    //             }
    //             copy="";
    //             copy += temp;
    //             temp="";
    //         }
    //     }

    //     cout<<ab_cnt<<" "<<ba_cnt;

    //     int ans = ab_cnt*x + ba_cnt*y;
    //     return ans;
    // }
};