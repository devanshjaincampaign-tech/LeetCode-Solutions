class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.size();
        int ans = 0;
        int last_end = -1; // Stores the end index of the last chosen palindrome

        // Iterate through all 2*n - 1 potential palindrome centers
        for (int center = 0; center < 2 * n - 1; ++center) {
            int l = center / 2;
            int r = l + (center % 2);

            // Expand outward from the center
            while (l > last_end && r < n && s[l] == s[r]) {
                // If we reach a length of at least k, take it greedily
                if (r - l + 1 >= k) {
                    ans++;
                    last_end = r;
                    break; // Move to the next center
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};