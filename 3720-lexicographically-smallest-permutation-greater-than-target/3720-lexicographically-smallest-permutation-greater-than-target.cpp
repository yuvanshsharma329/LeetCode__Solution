class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; --i) {
            vector<int> freq = count;
            bool possible = true;
            for (int k = 0; k < i; ++k) {
                if (--freq[target[k] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible)
                continue;

            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    string result = target.substr(0, i);
                    result += (char)('a' + c);
                    freq[c]--;

                    for (int ch = 0; ch < 26; ++ch) {
                        while (freq[ch] > 0) {
                            result += (char)('a' + ch);
                            freq[ch]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};
