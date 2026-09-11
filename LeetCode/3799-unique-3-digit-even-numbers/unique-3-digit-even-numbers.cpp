class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);

        for (int x : digits)
            cnt[x]++;

        int ans = 0;

        for (int num = 100; num <= 998; num++) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            if (c % 2 != 0)
                continue;

            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool ok = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > cnt[d]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans++;
        }

        return ans;
    }
};