class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int l = first[i];
            int r = last[i];
            bool valid = true;

            for (int j = l; j <= r; ++j) {
                int c = s[j] - 'a';
                if (first[c] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[c]);
            }

            if (valid) {
                intervals.push_back({r, l});
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<string> result;
        int prev_end = -1;
        for (const auto& p : intervals) {
            int r = p.first;
            int l = p.second;
            if (l > prev_end) {
                result.push_back(s.substr(l, r - l + 1));
                prev_end = r;
            }
        }

        return result;
    }
};