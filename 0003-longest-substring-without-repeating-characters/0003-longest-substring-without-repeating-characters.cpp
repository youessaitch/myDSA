class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n =s.size();
        unordered_map<char,int>mpp;
        int maxi = 0;
        while(i<n && j<n){
            if(mpp.find(s[j])==mpp.end()){
                mpp[s[j]]++;
                maxi = max(maxi,j-i+1);
                j++;
            }else{
                mpp[s[i]]--;
                if(mpp[s[i]]==0) mpp.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};