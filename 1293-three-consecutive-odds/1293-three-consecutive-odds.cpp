class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=arr[i]%2;
        for(int i=0;i<n-2;i++){
            if(v[i]==1){
                if(v[i+1]==1 && v[i+2]==1) return true;
            }
        }
        return false;
    }
};