class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        if (ones.size() < k) {
            return "";
        }

        int min_len = INT_MAX;
        string result = "";

        for (int i = 0; i <= (int)ones.size() - k; ++i) {
            int left = ones[i];
            int right = ones[i + k - 1];

            string candidate = s.substr(left, right - left + 1);
            int len = candidate.length();

            if (len < min_len) {
                min_len = len;
                result = candidate;
            } else if (len == min_len) {
                if (candidate < result) {
                    result = candidate;
                }
            }
        }

        return result;
    }
};
