class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, string &s, string &p) {
        // Base case: both s and p are fully matched
        if (i >= n && j >= m) return 1;

        // If pattern is exhausted but string is not
        if (j >= m) return 0;

        // If string is exhausted but pattern is not
        if (i >= n) {
            // Remaining characters in pattern should be '*'
            for (int k = j; k < m; k++) {
                if (p[k] != '*') return 0;
            }
            return 1;
        }

        // Memoization
        if (dp[i][j] != -1) return dp[i][j];

        // Matching character cases
        if (p[j] >= 'a' && p[j] <= 'z') {
            if (p[j] == s[i]) return dp[i][j] = solve(i + 1, j + 1, s, p);
            return dp[i][j] = 0;
        }

        // '?' matches any single character
        if (p[j] == '?') return dp[i][j] = solve(i + 1, j + 1, s, p);

        // '*' can match zero or more characters
        return dp[i][j] = solve(i, j + 1, s, p) || solve(i + 1, j + 1, s, p) || solve(i + 1, j, s, p);
    }

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();

        dp.resize(n + 1, vector<int>(m + 1, -1)); // Fix: second dimension is m+1

        return solve(0, 0, s, p);
    }
};
