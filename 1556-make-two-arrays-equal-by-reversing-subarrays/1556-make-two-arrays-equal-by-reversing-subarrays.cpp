class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();

        if(n!=m) return false;

        unordered_map<int,int> mpp1;
        // unordered_map<int,int> mpp2;

        for(auto it: target) mpp1[it]++;
        // for(auto it: arr) mpp2[it]++;

        // if(mpp1.size()!=mpp2.size()) return false;
        for(int i=0;i<arr.size();i++){
            if(mpp1.find(arr[i])!=mpp1.end()){
                mpp1[arr[i]]--;
                if(mpp1[arr[i]]==0) mpp1.erase(arr[i]);
            }else{
                return false;
            }
        }

        return true;
    }
};