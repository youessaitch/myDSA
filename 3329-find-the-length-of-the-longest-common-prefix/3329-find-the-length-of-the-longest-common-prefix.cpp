class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n,m;
        n = arr1.size();
        m = arr2.size();

        unordered_map<string,int> mpp;

        for(int i=0;i<n;i++){
            int temp = arr1[i];
            string s = to_string(temp);
            string h = "";
            for(int j=0;j<s.size();j++){
                h+=s[j];
                mpp[h]++;
            }
        }

        int maxi = 0;

        for(int i=0;i<m;i++){
            int temp = arr2[i];
            string s = to_string(temp);
            string h = "";
            for(int j=0;j<s.size();j++){
                h+=s[j];
                if(mpp.find(h)!=mpp.end()){
                    maxi = max(maxi,(int)h.size());
                }else break;
            }
        }
        
        return maxi;
    }
};