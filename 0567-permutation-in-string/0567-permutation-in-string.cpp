class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(m<n) return false;

        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;

        for(auto &it: s1) mpp1[it]++;

        int i=0,j=0;
        
        while(j<n){
            mpp2[s2[j]]++;
            j++;
        }

        if(mpp1==mpp2) return true;

        while(j<m){
            mpp2[s2[j]]++;
            mpp2[s2[i]]--;
            if(mpp2[s2[i]]==0) mpp2.erase(s2[i]);
            i++;
            j++;

            if(mpp1==mpp2) return true;
        }

        return false;
    }
};