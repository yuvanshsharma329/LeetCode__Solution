class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int diff = 0;
        int q_diff = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q_diff++;
            } else {
                diff += (num[i] - '0');
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q_diff--;
            } else {
                diff -= (num[i] - '0');
            }
        }

        if ((q_diff % 2) != 0) {
            return true;
        }

        return diff + (q_diff / 2) * 9 != 0;
    }
};
