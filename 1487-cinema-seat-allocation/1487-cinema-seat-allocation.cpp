class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int ans = 0;
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<reservedSeats.size();i++){
            mpp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }

        ans += 2*(n-mpp.size());
        for (auto& it : mpp) {
            auto& v = it.second;
            bool left = true, middle = true, right = true;

            for (int seat : v) {
                if (seat >= 2 && seat <= 5) left = false;
                if (seat >= 4 && seat <= 7) middle = false;
                if (seat >= 6 && seat <= 9) right = false;
            }

            if (left && right) ans += 2;         
            else if (left || middle || right) ans += 1;
        }

        return ans;
    }
};