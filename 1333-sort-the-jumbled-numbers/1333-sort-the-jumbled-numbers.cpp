class Solution {
public:
    int n,m;
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        n = mapping.size();
        m = nums.size();

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[i] = mapping[i];
        }
        vector<pair<int,int>> v;
        for(auto it: nums){
            string num = to_string(it);
            for(int i=0;i<num.size();i++){
                num[i] = '0' + mpp[num[i] - '0'];
            }
            int no = stoi(num);
            v.push_back({no,it});
        }

        auto lambda = [](const pair<int,int> &A, const pair<int,int> &B){
            // if(A.first != B.first) return A.first<B.first;
            // else return A.second==B.second;
            return A.first<B.first;
        };

        stable_sort(v.begin(),v.end(),lambda);
        vector<int> ans;
        for(auto it: v){
            ans.push_back(it.second);
        }
        return ans;

    }
};