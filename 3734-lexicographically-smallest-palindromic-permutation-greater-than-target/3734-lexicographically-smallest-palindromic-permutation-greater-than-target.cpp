class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }

        // Invalid if more than 1 odd-frequency character
        if (odd_count > 1)
            return "";

        int m = n / 2;
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        // Helper to reconstruct full palindrome from first half
        auto get_palindrome = [&](const string& half) -> string {
            string res = half;
            if (n % 2 != 0) {
                res += mid_char;
            }
            string rev = half;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };

        string best_res = "";

        // Try prefix lengths p from m down to 0
        for (int p = m; p >= 0; --p) {
            // Check if target[0...p-1] can be built using available half_count
            vector<int> cur_count = half_count;
            bool possible = true;
            for (int i = 0; i < p; ++i) {
                int ch = target[i] - 'a';
                if (cur_count[ch] <= 0) {
                    possible = false;
                    break;
                }
                cur_count[ch]--;
            }
            if (!possible)
                continue;

            string prefix = target.substr(0, p);

            if (p == m) {
                // Exact match on the first half
                string cand = get_palindrome(prefix);
                if (cand > target) {
                    if (best_res == "" || cand < best_res) {
                        best_res = cand;
                    }
                }
            } else {
                // Try choosing a character at index p strictly greater than
                // target[p]
                int start_ch = target[p] - 'a' + 1;
                for (int c = start_ch; c < 26; ++c) {
                    if (cur_count[c] > 0) {
                        vector<int> rem_count = cur_count;
                        rem_count[c]--;

                        string half = prefix;
                        half += (char)('a' + c);

                        // Fill the rest greedily with smallest available
                        // characters
                        for (int i = 0; i < 26; ++i) {
                            while (rem_count[i] > 0) {
                                half += (char)('a' + i);
                                rem_count[i]--;
                            }
                        }

                        string cand = get_palindrome(half);
                        if (cand > target) {
                            if (best_res == "" || cand < best_res) {
                                best_res = cand;
                            }
                        }
                        break; // Smallest valid character chosen for position p
                    }
                }
            }
        }

        return best_res;
    }
};
