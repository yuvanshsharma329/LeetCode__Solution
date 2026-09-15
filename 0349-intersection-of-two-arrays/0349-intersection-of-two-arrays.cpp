class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Insert all elements of nums1 into a hash set to remove duplicates
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> resultSet;
        
        // Iterate through nums2 and check if the element exists in set1
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num); // resultSet handles keeping numbers unique
            }
        }
        
        // Convert the result set back into a vector
        return std::vector<int>(resultSet.begin(), resultSet.end());
    }
};