class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> a = nums, v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();
        vector<long long> b(m + 1), c(m + 1);

        auto add = [&](int i, int d, long long val) {
            for (; i <= m; i += i & -i)
                (d ? c[i] : b[i]) += val;
        };

        auto sum = [&](int i, int d) {
            long long s = 0;
            for (; i; i -= i & -i)
                s += d ? c[i] : b[i];
            return s;
        };

        auto getCost = [&]() {
            int l = 1, r = m, med = 0;
            int need = (x + 1) / 2;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (sum(mid, 0) >= need) med = mid, r = mid - 1;
                else l = mid + 1;
            }

            long long z = v[med - 1];
            long long cnt = sum(med, 0), s = sum(med, 1);
            long long total = sum(m, 1);

            return z * cnt - s + (total - s) - z * (x - cnt);
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
            add(p, 0, 1);
            add(p, 1, a[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            int p = lower_bound(v.begin(), v.end(), a[i-x]) - v.begin() + 1;
            add(p, 0, -1);
            add(p, 1, -a[i-x]);

            p = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
            add(p, 0, 1);
            add(p, 1, a[i]);

            cost[i-x+1] = getCost();
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> dp(n + 1, 0), ndp(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(ndp.begin(), ndp.end(), INF);

            for (int i = 1; i <= n; i++) {
                ndp[i] = ndp[i-1];

                if (i >= x)
                    ndp[i] = min(ndp[i], dp[i-x] + cost[i-x]);
            }

            dp.swap(ndp);
        }

        return dp[n];
    }
};