class Solution {
    vector<vector<int>> dp;
    string s;

    int solve(int i, int j) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1);

        return dp[i][j] = min(1 + solve(i + 1, j),
                                1 + solve(i, j - 1));
    }

public:
    int minInsertions(string s) {
        this->s = s;
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);

    }
};