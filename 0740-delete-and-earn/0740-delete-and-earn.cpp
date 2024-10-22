#define ll long long
#define pii pair<int,int>
class Solution {
public:
    //prepared a map of frequency,
    //dp of size *max_element+1
    //applying dp on the map prepared

    int solve(int i, int m, unordered_map<int,int> &mpp, vector<int> &dp){
        if(i>=m+1) return 0; //if greater than max element return

        if(dp[i]!=-1) return dp[i];

        int take = mpp[i] + solve(i + 2, m, mpp, dp);

        int notTake = solve(i+1,m,mpp,dp);

        return dp[i] = max(take,notTake);
    }

    int deleteAndEarn(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto &it: nums){
            mpp[it]++;
        }

        vector<int> arr;
        for(auto &it: mpp){
            it.second = it.second*it.first;
            arr.push_back(it.first);
        }

        sort(arr.begin(),arr.end());
        int m = arr[arr.size()-1]; //max element

        vector<int> dp1(m+1,-1);
        
        int ans1 = solve(0,m,mpp,dp1);
        // int ans2 = solve(1,m,mpp,dp1);

        return max(ans1,0);
    }
};


// int deleteAndEarn(vector<int>& nums) {
    //     int n = nums.size();
    //     int score = 0;

    //     priority_queue<pii> pq;
    //     map<int,int,greater<int>> mpp;
    //     for(auto it: nums) mpp[it]++;

    //     for(auto it: mpp){
    //         cout<<it.first<<" "<<it.second<<endl;
    //         pq.push({it.second*it.first,it.first});
    //     }

    //     while(!pq.empty()){
    //         auto it = pq.top();
    //         // cout<<it.first<<" "<<it.second<<endl;
    //         if(mpp.find(it.second)!=mpp.end()){
    //             score += it.first;
    //             int oneplus = it.second+1;
    //             int oneminus = it.second-1;
    //             if(mpp.find(oneplus)!=mpp.end()) mpp.erase(oneplus);
    //             if(mpp.find(oneminus)!=mpp.end()) mpp.erase(oneminus);
    //             pq.pop();
    //             mpp.erase(it.second);
    //         }else{
    //             pq.pop();
    //         }
    //     }

       
    //     return score;
    // }