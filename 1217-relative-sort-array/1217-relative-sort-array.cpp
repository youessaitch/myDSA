class Solution {
public:
    //tc = O(N + M)
    //sc = O(N)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        for(auto it: arr1) mpp[it]++;
        vector<int> ans;
        for(int i=0;i<arr2.size();i++){
            while(mpp[arr2[i]]!=0){
                ans.push_back(arr2[i]);
                mpp[arr2[i]]--;
            }
        }

        for(auto it:mpp){
            if(it.second!=0){
                while(it.second!=0){
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }
        return ans;
    }
};