class Solution {
public:
    void splitKrdo(string s, vector<string> &v) {
        string str = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                v.push_back(str);
                str = "";
            } else {
                str += s[i];
            }
        }
        v.push_back(str); // Add the last word after the loop.
    }

    bool areSentencesSimilar(string s1, string s2) {
        vector<string> w1;
        vector<string> w2;

        // Split the sentences into words.
        splitKrdo(s1, w1);
        splitKrdo(s2, w2);

        // Ensure w1 is the longer (or equal) sentence.
        if(w1.size() < w2.size()) swap(w1, w2);

        int p = w1.size();
        int q = w2.size();

        // left and right pointers
        int l = 0, r1 = p-1, r2 = q-1;

        // Count matching words from the start.
        while(l < q && w1[l] == w2[l]) l++;

        while(r1>=0 && r2>=0 && w1[r1] == w2[r2]){
            r1--;
            r2--;
        }

        int ans = 0;

        // if l crossed any of r or r1 that means we have found an answer
        if((l>r1) || (l>r2)) ans = 1;
        return ans;
    }
};




//araghghhhhhhhhhhhhhh
// cout<<s1<<" + "<<s2<<endl;

//         unordered_map<string,int> mp1;
//         unordered_map<string,int> mp2;

//         cout<<s2<<endl;

//         string str = "";
//         for(int i=0;i<m;i++){
//             if(s2[i]==' '){
//                 mp2[str]++;
//                 str = "";
//             }else{
//                 str += s2[i];
//             }
//         }
//         mp2[str]++;

//         for(auto it: mp2) cout<<it.first<<" "<<it.second<<endl;
        
//         int cnt = 0;
//         bool flag = 0;
//         vector<string> ch;
//         str = "";
//         string check = "";
//         for(int i=0;i<n;i++){
//             if(s1[i]==' '){
//                 if(mp2.find(str)==mp2.end()){
//                     flag = 1;
//                 }else{
//                     mp2[str]--;
//                     if(mp2[str]==0) mp2.erase(str);
//                     flag = 0;
//                 }

//                 if(flag) check += str;
//                 if(!flag){
//                     if(check.size()>0)
//                         ch.push_back(check);
//                     check = "";
//                 }
//                 str = "";
                
//             }else{
//                 str += s1[i];
//             }
//         }
//         if(mp2.find(str)==mp2.end()){
//             flag = 1;
//         }else{
//             mp2[str]--;
//             if(mp2[str]==0) mp2.erase(str);
//             flag = 0;
//         }

//         if(flag) check += str;
        
//         if(check.size()>0)
//             ch.push_back(check);

//         if(ch.size()==0 || ch.size()==1) return true;
//         return false;