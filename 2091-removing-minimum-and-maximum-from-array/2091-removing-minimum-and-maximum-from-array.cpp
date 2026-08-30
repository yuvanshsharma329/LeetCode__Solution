class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        int minIdx = 0, maxIdx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        int removeFront = j + 1;
        int removeBack = n - i;
        int removeBothSides = (i + 1) + (n - j);

        return min({removeFront, removeBack, removeBothSides});
    }
};
