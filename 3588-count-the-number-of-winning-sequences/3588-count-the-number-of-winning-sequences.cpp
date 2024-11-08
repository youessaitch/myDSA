#define ll long long
class Solution {
public:
    int n;
    int mod = 1e9+7;
    vector<vector<vector<ll>>> dp;

    ll solve(int i, int prev, ll cnt, string &t) {
        // Ensure cnt is within [-1001, 1001]
        // if (cnt < -1001 || cnt > 1001) return 0;  // No valid configuration

        if (i >= n) {
            return cnt > 0 ? 1 : 0;
        }

        if (dp[i][prev][cnt + 1000] != -1) return dp[i][prev][cnt + 1000];

        ll f = 0, w = 0, e = 0;
        if (t[i] == '0') {
            if (prev != 0) f = solve(i + 1, 0, cnt, t) % mod;      // 0 vs 0 -> no one won
            if (prev != 1) w = solve(i + 1, 1, cnt + 1, t) % mod;  // 0 vs 1 -> bob won
            if (prev != 2) e = solve(i + 1, 2, cnt - 1, t) % mod;  // 0 vs 2 -> alice won
        } else if (t[i] == '1') {
            if (prev != 0) f = solve(i + 1, 0, cnt - 1, t) % mod;  // 0 vs 1 -> alice won
            if (prev != 1) w = solve(i + 1, 1, cnt, t) % mod;      // 1 vs 1 -> no one won
            if (prev != 2) e = solve(i + 1, 2, cnt + 1, t) % mod;  // 2 vs 1 -> bob won
        } else if (t[i] == '2') {
            if (prev != 0) f = solve(i + 1, 0, cnt + 1, t) % mod;  // 0 vs 2 -> alice won
            if (prev != 1) w = solve(i + 1, 1, cnt - 1, t) % mod;  // 1 vs 2 -> bob won
            if (prev != 2) e = solve(i + 1, 2, cnt, t) % mod;      // 2 vs 2 -> no one won
        }
        return dp[i][prev][cnt + 1000] = (f + w + e);
    }

    int countWinningSequences(string s) {
        n = s.size();
        string t;
        for (char c : s) {
            if (c == 'F') t += '0';
            else if (c == 'W') t += '1';
            else if (c == 'E') t += '2';
        }

        dp.assign(n + 1, vector<vector<ll>>(3, vector<ll>(2001, -1)));  

        ll ans = (solve(0, 0, 0, t) + solve(0, 1, 0, t) + solve(0, 2, 0, t));
        return (ans / 2) % mod;
    }
};
