#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len;
    int prefix_len;
    int suffix_len;
};

class Solution {
private:
    vector<Node> tree;
    string str;

    void pull(int node, int start, int end) {
        int mid = start + (end - start) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        int left_len = mid - start + 1;
        int right_len = end - mid;

        // Base max_len from children
        tree[node].max_len = max(tree[left_child].max_len, tree[right_child].max_len);

        // Standard prefix and suffix lengths
        tree[node].prefix_len = tree[left_child].prefix_len;
        tree[node].suffix_len = tree[right_child].suffix_len;

        // Check if characters at the boundary match
        if (str[mid] == str[mid + 1]) {
            // Update internal max combining across the split
            tree[node].max_len = max(tree[node].max_len, tree[left_child].suffix_len + tree[right_child].prefix_len);

            // Extend prefix if left segment is fully uniform
            if (tree[left_child].prefix_len == left_len) {
                tree[node].prefix_len = left_len + tree[right_child].prefix_len;
            }

            // Extend suffix if right segment is fully uniform
            if (tree[right_child].suffix_len == right_len) {
                tree[node].suffix_len = right_len + tree[left_child].suffix_len;
            }
        }
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        pull(node, start, end);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            str[idx] = ch;
            tree[node] = {1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        pull(node, start, end);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        int n = str.length();
        int k = queryIndices.size();

        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree[1].max_len;
        }

        return result;
    }
};