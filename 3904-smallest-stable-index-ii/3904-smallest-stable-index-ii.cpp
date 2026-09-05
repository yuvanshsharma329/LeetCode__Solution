class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff_min[i] = min(nums[i], suff_min[i + 1]);
        }
        
        int current_pref_max = nums[0];
        for (int i = 0; i < n; ++i) {
            current_pref_max = max(current_pref_max, nums[i]);
            
            if (current_pref_max - suff_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};