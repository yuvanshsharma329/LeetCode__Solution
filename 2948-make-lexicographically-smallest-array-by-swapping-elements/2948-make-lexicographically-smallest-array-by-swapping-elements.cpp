class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> sorted_pairs(n);
        for (int i = 0; i < n; ++i) {
            sorted_pairs[i] = {nums[i], i};
        }

        sort(sorted_pairs.begin(), sorted_pairs.end());

        vector<int> result(n);
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n &&
                   sorted_pairs[j].first - sorted_pairs[j - 1].first <= limit) {
                j++;
            }

            vector<int> group_indices;
            group_indices.reserve(j - i);
            for (int k = i; k < j; ++k) {
                group_indices.push_back(sorted_pairs[k].second);
            }

            sort(group_indices.begin(), group_indices.end());

            for (int k = 0; k < group_indices.size(); ++k) {
                result[group_indices[k]] = sorted_pairs[i + k].first;
            }

            i = j;
        }

        return result;
    }
};
