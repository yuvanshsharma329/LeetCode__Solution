#include <algorithm>
#include <vector>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
        }

        int current_max = nums[0];
        for (int i = 0; i < n; ++i) {
            current_max = std::max(current_max, nums[i]);
            if ((long long)current_max - suffix_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};