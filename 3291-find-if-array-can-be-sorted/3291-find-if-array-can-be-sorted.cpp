class Solution {
public:
    int cntBits(int n){
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(n & (1<<i)) cnt++;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        vector<int> t;
        int prev = cntBits(nums[0]);
        for(int i=0;i<n;i++){
            int cnt = cntBits(nums[i]);
            if(t.size()==0 || cnt == prev) t.push_back(nums[i]);
            else{
                sort(t.begin(),t.end());
                v.push_back(t);
                t.clear();
                prev = cnt;
                t.push_back(nums[i]);
            }
        }
        if(!t.empty()) {
            sort(t.begin(), t.end());
            v.push_back(t);
        }

        for(int i = 1; i < v.size(); i++) {
            if(v[i-1].back() > v[i].front()) {
                return false;
            }
        }
   
        return true;
    }
};