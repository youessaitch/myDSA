class Solution {
public:
    bool check(int i, int j, vector<int> &nums){
        bool ch = true;
        for(int p=i;p<j;p++){
            if(nums[p+1]<=nums[p] || (nums[p+1]-nums[p]>1)){
                ch = false;
                break;
            }
        }
        return ch;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        if(check(0,k-1,nums)) ans.push_back(nums[k-1]);
        else ans.push_back(-1);

        int i=1,j=k;
        while(j<n){
            if(check(i,j,nums)) ans.push_back(nums[j]);
            else ans.push_back(-1);
            i++;
            j++;
        }

        return ans;
    }
};