class Solution {
    struct Node{
        int prod;
        array<int, 5>cnt;
        Node(){
            prod = 1;
            cnt.fill(0);
        }
    };

    int n, k;
    vector<Node> tree;
    vector<int> a;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.prod = (L.prod * R.prod) % k;
        res.cnt.fill(0);

        for (int r = 0; r < k; r++) {
            res.cnt[r] += L.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (L.prod * r) % k;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            int v = a[l] % k;
            tree[idx].prod = v;
            tree[idx].cnt.fill(0);
            tree[idx].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            int v = val % k;
            tree[idx].prod = v;
            tree[idx].cnt.fill(0);
            tree[idx].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        n = nums.size();
        k = K;
        a = nums;

        tree.resize(4 * n + 5);
        build(1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {
            int pos = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            a[pos] = val;
            update(1, 0, n - 1, pos, val);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};