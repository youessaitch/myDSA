class Solution {
public:
    vector<char> ch = {'a','e','i','o','u'};
    bool doesAliceWin(string s) {
        int n = s.size();
        vector<int> odd;
        vector<int> even;

        int cnt = 0;
        for(int i=0;i<n;i++){
            auto temp = s[i];
            for(int j=0;j<5;j++){
                if(ch[j] == temp) cnt++;
            }
            if(cnt%2==0) even.push_back(i);
            else odd.push_back(i);
        }

        if(cnt==0) return false;
        return true;
    }
};