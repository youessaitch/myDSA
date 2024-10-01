class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            arr[i] = (arr[i]%k + k)%k; //remainder
            mpp[arr[i]]++;
        }

        for(int i=0;i<n;i++){
            int f = arr[i]; //remainder

            if(f==0){
                if(mpp[f]%2 != 0){
                    return false;
                }
            }else{
                if(mpp[f] != mpp[k-f]){
                    return false;
                }
            }
        }

        return true;
    }
};