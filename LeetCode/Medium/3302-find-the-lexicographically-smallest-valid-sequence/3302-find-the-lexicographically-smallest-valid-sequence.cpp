class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> right(m + 1, -1);
        right[m] = n;

        for (int j = m - 1; j >= 0; --j) {
            int pos = right[j + 1] - 1;
            while (pos >= 0 && word1[pos] != word2[j]) {
                pos--;
            }
            right[j] = pos;
        }

        vector<vector<int>> pos_list(26);
        for (int i = 0; i < n; ++i) {
            pos_list[word1[i] - 'a'].push_back(i);
        }

        auto get_next_pos = [&](int p1, char c) -> int {
            const auto& list = pos_list[c - 'a'];
            auto it = lower_bound(list.begin(), list.end(), p1);
            if (it == list.end()) return -1;
            return *it;
        };

        vector<int> ans(m);
        int p1 = 0;
        bool used_mismatch = false;

        for (int i = 0; i < m; ++i) {
            if (used_mismatch) {
                int idx = get_next_pos(p1, word2[i]);
                if (idx == -1 || idx >= right[i + 1]) {
                    return {};
                }
                ans[i] = idx;
                p1 = idx + 1;
            } else {
                if (p1 < right[i + 1]) {
                    ans[i] = p1;
                    if (word1[p1] != word2[i]) {
                        used_mismatch = true;
                    }
                    p1 = p1 + 1;
                } else {
                    int idx = get_next_pos(p1, word2[i]);
                    if (idx == -1) {
                        return {};
                    }
                    ans[i] = idx;
                    p1 = idx + 1;
                }
            }
        }

        return ans;
    }
};