class Solution {
public:
    int distinctSubseqII(std::string s) {
        int MOD = 1e9 + 7;
        int n = s.length();
        
        std::vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
        std::vector<long long> last(26, 0);
        
        for (int i = 1; i <= n; ++i) {
            char ch = s[i - 1];
            int idx = ch - 'a';
            
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            dp[i] = (dp[i] - last[idx] + MOD) % MOD;
            
            last[idx] = dp[i - 1];
        }
        
        return (dp[n] - 1 + MOD) % MOD;
    }
};