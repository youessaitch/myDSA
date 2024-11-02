class Solution {
public:
    void parse(string &s, vector<string> &v){
        stringstream ss(s);
        string t = "";
        char del = ' ';
        while(getline(ss,t,del)){
            v.push_back(t);
        }
    }

    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        vector<string> v;
        parse(sentence,v);

        bool ans = true;
        for(int i=0;i<v.size()-1;i++){
            if(v[i].back() != v[i+1][0]) ans = false;
        }
        int m = v.size();

        if(v[0][0] != v[m-1].back()) ans = false;

        return ans;
    }
};