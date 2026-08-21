

class Solution {
    long long lcm(long long a, long long b) { return (a / std::gcd(a, b)) * b; }

    long long countAmounts(long long mx, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long currentLcm = 1;
            int bitCount = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bitCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > mx)
                        break;
                }
            }

            if (currentLcm <= mx) {
                if (bitCount % 2 == 1) {
                    count += mx / currentLcm;
                } else {
                    count -= mx / currentLcm;
                }
            }
        }
        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};