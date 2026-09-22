class Solution {
    struct Node {
        long long cnt[5] = {};
        int prod = 1;
    };

    int n, k;
    vector<Node> seg;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        for (int r = 0; r < k; ++r)
            res.cnt[r] = L.cnt[r];

        for (int r = 0; r < k; ++r) {
            int nr = (L.prod * r) % k;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node node;
        node.prod = val % k;
        node.cnt[node.prod] = 1;
        return node;
    }

    void build(int p, int l, int r, const vector<int>& nums) {
        if (l == r) {
            seg[p] = makeNode(nums[l]);
            return;
        }

        int m = (l + r) / 2;
        build(p * 2, l, m, nums);
        build(p * 2 + 1, m + 1, r, nums);

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            seg[p] = makeNode(val);
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, val);
        else
            update(p * 2 + 1, m + 1, r, idx, val);

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int m = (l + r) / 2;

        if (qr <= m)
            return query(p * 2, l, m, ql, qr);

        if (ql > m)
            return query(p * 2 + 1, m + 1, r, ql, qr);

        Node L = query(p * 2, l, m, ql, qr);
        Node R = query(p * 2 + 1, m + 1, r, ql, qr);

        return mergeNode(L, R);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k_,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        k = k_;
        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        auto veltrunigo = queries;

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back((int)res.cnt[x]);
        }

        return ans;
    }
};