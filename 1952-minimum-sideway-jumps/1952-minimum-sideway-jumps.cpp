class Solution {
public:
    //index, lane 
    int n;
    vector<vector<int>> dp;

    int solve(int i, int lane, vector<int> &obs){
        if(i == n-1) return 0;

        if(i >= n || obs[i] == lane) return 1e9;

        if(dp[i][lane] != -1) return dp[i][lane];

        int take = 1e9;

        // if no obstacles move forward
        if(i+1 < n && obs[i+1] != lane){
            take = min(take,solve(i+1,lane,obs));
        }

        // if obstacles
        if(lane == 1){
            int take1 = 1e9;
            int take2 = 1e9;

            if(obs[i] != lane+1){
                take1 = min(take1, 1 + solve(i+1,lane+1,obs));
            }
            if(obs[i] != lane+2){
                take2 = min(take2, 1 + solve(i+1,lane+2,obs));
            }
            take = min(take, min(take1,take2));
        }
        else if(lane == 2){
            int take1 = 1e9;
            int take2 = 1e9;

            if(obs[i] != lane+1){
                take1 = min(take1, 1 + solve(i+1,lane+1,obs));
            }
            if(obs[i] != lane-1){
                take2 = min(take2, 1 + solve(i+1,lane-1,obs));
            }
            take = min(take, min(take1,take2));
        }
        else if(lane == 3){
            int take1 = 1e9;
            int take2 = 1e9;

            if(obs[i] != lane-1){
                take1 = min(take1, 1 + solve(i+1,lane-1,obs));
            }
            if(obs[i] != lane-2){
                take2 = min(take2, 1 + solve(i+1,lane-2,obs));
            }
            take = min(take, min(take1,take2));
        }
        //     take = min(take,1 + min(solve(i+1,lane+1,obs),solve(i+1,lane+2,obs)));
        // if(lane == 2)
        //     take = min(take,1 + min(solve(i+1,lane+1,obs),solve(i+1,lane-1,obs)));
        // if(lane == 3)
        //     take = min(take,1 + min(solve(i+1,lane-1,obs),solve(i+1,lane-2,obs)));

        return dp[i][lane] = take;
    }

    int minSideJumps(vector<int>& obs) {
        n = obs.size();

        dp.resize(n,vector<int>(4,-1));

        return solve(0,2,obs);
    }
};