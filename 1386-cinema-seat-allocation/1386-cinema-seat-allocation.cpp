class Solution {
public:
    int maxNumberOfFamilies(int n,
                            std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> rowMasks;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }

        int maxGroups = 2 * n;

        for (const auto& [row, mask] : rowMasks) {
            bool leftPossible = !(mask & 0b00001111);
            bool rightPossible = !(mask & 0b11110000);
            bool middlePossible = !(mask & 0b00111100);

            if (leftPossible && rightPossible) {
                continue;
            } else if (leftPossible || rightPossible || middlePossible) {
                maxGroups -= 1;
            } else {
                maxGroups -= 2;
            }
        }

        return maxGroups;
    }
};
