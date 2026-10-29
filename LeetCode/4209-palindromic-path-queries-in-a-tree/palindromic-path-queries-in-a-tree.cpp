class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto &e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        int L = 17, timer = 0;
        vector<vector<int>> up(L, vector<int>(n));
        vector<int> in(n), out(n), dep(n), par(n), pre(n), bit(n + 2), order, st = {0};

        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            in[u] = ++timer; order.push_back(u);
            for (int v : g[u]) if (v != par[u] && (u || v)) {
                par[v] = u; dep[v] = dep[u] + 1; st.push_back(v);
            }
        }

        for (int u : order) {
            up[0][u] = par[u];
            pre[u] = (u ? pre[par[u]] : 0) ^ (1 << (s[u] - 'a'));
            for (int j = 1; j < L; j++) up[j][u] = up[j-1][up[j-1][u]];
        }
        for (int u : order) out[u] = in[u];
        for (int i = n-1; i > 0; i--) out[par[order[i]]] = max(out[par[order[i]]], out[order[i]]);

        auto upd = [&](int i, int x) { for (; i <= n; i += i & -i) bit[i] ^= x; };
        auto get = [&](int i) { int x = 0; for (; i; i -= i & -i) x ^= bit[i]; return x; };
        auto lca = [&](int u, int v) {
            if (dep[u] < dep[v]) swap(u, v);
            for (int d = dep[u]-dep[v], j = 0; j < L; j++) if (d >> j & 1) u = up[j][u];
            if (u == v) return u;
            for (int j = L-1; j >= 0; j--) if (up[j][u] != up[j][v]) u = up[j][u], v = up[j][v];
            return par[u];
        };

        vector<bool> ans;
        for (string q : queries) {
            string op; int u, v;
            stringstream ss(q); ss >> op >> u;
            if (op == "update") {
                char c; ss >> c;
                int x = (1 << (s[u]-'a')) ^ (1 << (c-'a'));
                upd(in[u], x); upd(out[u]+1, x); s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v), x = pre[u]^get(in[u])^pre[v]^get(in[v])^(1 << (s[w]-'a'));
                ans.push_back(!(x & (x-1)));
            }
        }
        return ans;
    }
};