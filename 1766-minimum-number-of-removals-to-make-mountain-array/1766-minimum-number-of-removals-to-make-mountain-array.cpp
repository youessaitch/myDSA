class Solution {
public:
    int n;
    // int LIS(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
    //     if(i>=n) return 0;

    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];

    //     int take = 0;
    //     if(prev == -1 || nums[i] > nums[prev]){
    //         take = 1 + LIS(i+1,i,nums,dp);
    //     }

    //     int notTake = LIS(i+1,prev,nums,dp);

    //     return dp[i][prev+1] = max(take,notTake);
    // }

    void LISbinarysearch(vector<int> &nums, vector<int> &dp){
        vector<int> temp;
        temp.push_back(nums[0]);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            int ind;
            if(nums[i] > temp.back()){ 
                temp.push_back(nums[i]);
                ind = temp.size()-1;
            }
            else{
                ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i]; 
            }
            dp[i] = ind+1;
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();

        vector<int> leftLIS(n,0);
        vector<int> rightLIS(n,0);

        vector<int> revNums;
        revNums = nums;
        reverse(nums.begin(),nums.end());

        LISbinarysearch(nums,leftLIS);
        LISbinarysearch(revNums,rightLIS);
        reverse(leftLIS.begin(),leftLIS.end());

        int maxi = -1e9;
        int index = -1;
        for(int i=0;i<n;i++){
            if(leftLIS[i]!=1 && rightLIS[i]!=1){
                int tempSum = leftLIS[i] + rightLIS[i];
                if(tempSum > maxi){
                    maxi = tempSum;
                    index = i;
                }
            }
        }

        cout<<maxi<<" "<<index<<endl;

        for(auto it: leftLIS) cout<<it<<" ";
        cout<<endl;

        for(auto it: rightLIS) cout<<it<<" ";
        cout<<endl;

        return n - (maxi-1);
    }
};

