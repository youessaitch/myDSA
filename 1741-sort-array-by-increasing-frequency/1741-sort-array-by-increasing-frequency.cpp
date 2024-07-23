class Solution {
public:
    int n;
    vector<int> frequencySort(vector<int>& nums) {
        n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it: nums) mpp[it]++;
        vector<int> ans(n);
        vector<pair<int,int>> v;
        for(auto it: mpp){
            v.push_back({it.second,it.first});
        } 
        auto lambda = [](const pair<int,int> &A, const pair<int,int> &B){
            if(A.first == B.first) return A.second>B.second;
            else return A.first<B.first;
        };

        sort(v.begin(),v.end(),lambda);
        int i=0;
        for(auto it: v){
            int temp = it.first;
            while(temp!=0){
                ans[i] = it.second;
                i++;
                temp--;
            }
        }
        return ans;
    }
};