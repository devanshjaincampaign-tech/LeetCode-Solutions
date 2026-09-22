class Solution {
    struct Node {
        int remain[5] = {0};
        int prod = 1;
    };

    class SegmentTree {
        int n;
        int k;
        vector<Node> tree;

        Node merge(const Node& left, const Node& right) const {
            Node res;
            res.prod = (left.prod * right.prod) % k;
            for (int i = 0; i < k; ++i) {
                res.remain[i] += left.remain[i];
                res.remain[(i * left.prod) % k] += right.remain[i];
            }
            return res;
        }

        void build(const vector<int>& nums, int cur, int l, int r) {
            if (l == r) {
                tree[cur].remain[nums[l]] = 1;
                tree[cur].prod = nums[l];
                return;
            }
            int mid = l + (r - l) / 2;
            build(nums, 2 * cur + 1, l, mid);
            build(nums, 2 * cur + 2, mid + 1, r);
            tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
        }

        void update(int cur, int l, int r, int idx, int val) {
            if (l == r) {
                for (int i = 0; i < k; ++i) {
                    tree[cur].remain[i] = 0;
                }
                tree[cur].remain[val] = 1;
                tree[cur].prod = val;
                return;
            }
            int mid = l + (r - l) / 2;
            if (idx <= mid) {
                update(2 * cur + 1, l, mid, idx, val);
            } else {
                update(2 * cur + 2, mid + 1, r, idx, val);
            }
            tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
        }

        Node query(int cur, int l, int r, int ql, int qr) const {
            if (ql <= l && r <= qr) {
                return tree[cur];
            }
            int mid = l + (r - l) / 2;
            if (qr <= mid) {
                return query(2 * cur + 1, l, mid, ql, qr);
            }
            if (ql > mid) {
                return query(2 * cur + 2, mid + 1, r, ql, qr);
            }
            return merge(query(2 * cur + 1, l, mid, ql, qr), query(2 * cur + 2, mid + 1, r, ql, qr));
        }

    public:
        SegmentTree(const vector<int>& nums, int k) : n(nums.size()), k(k), tree(4 * n) {
            build(nums, 0, 0, n - 1);
        }

        void update(int idx, int val) {
            update(0, 0, n - 1, idx, val);
        }

        int query(int ql, int qr, int x) const {
            if (ql > qr) return 0;
            Node res = query(0, 0, n - 1, ql, qr);
            return res.remain[x];
        }
    };

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] %= k;
        }

        SegmentTree st(nums, k);
        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1] % k;
            int start = q[2];
            int x = q[3];

            st.update(idx, val);
            result.push_back(st.query(start, n - 1, x));
        }

        return result;
    }
};