class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp;
        temp = s;
        temp+=s;
        int i=0,r=s.size()-1;
        while(r<temp.size()){
            if(temp.substr(i,s.size()) == goal) return true;
            i++;
            r++;
        }
        return false;
    }
};