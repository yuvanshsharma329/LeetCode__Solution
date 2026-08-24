class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();

        // Compute prefix sums
        std::vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Base case: Taking all stones (index n-1)
        int dp = pref[n - 1];

        // Transition backwards from n-2 down to index 1 (x >= 2 stones)
        for (int i = n - 2; i >= 1; --i) {
            dp = std::max(dp, pref[i] - dp);
        }

        return dp;
    }
};