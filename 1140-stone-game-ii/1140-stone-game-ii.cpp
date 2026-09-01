class Solution {
public:
int dp[101][101];
vector<int> suffix;
int n;
int solve(int index, int M, vector<int>& piles) {
    if (index >= n)
        return 0;

    if (2 * M >= n - index)
        return suffix[index];

    if (dp[index][M] != -1)
        return dp[index][M];

    int maximum = 0;

    for (int X = 1; X <= 2 * M; X++) {
        int opponent = solve(index + X, max(M, X), piles);

        maximum = max(maximum, suffix[index] - opponent);
    }

    return dp[index][M] = maximum;
}

int stoneGameII(vector<int>& piles) {
    n = piles.size();

    suffix.resize(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + piles[i];
    }

    memset(dp, -1, sizeof(dp));

    return solve(0, 1, piles);
}

};
