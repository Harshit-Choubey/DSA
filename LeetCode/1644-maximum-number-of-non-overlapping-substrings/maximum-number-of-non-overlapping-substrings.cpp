class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> f(26, s.size()), l(26, -1);

        for (int i = 0; i < s.size(); i++) {
            f[s[i] - 'a'] = min(f[s[i] - 'a'], i);
            l[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> v;

        for (int c = 0; c < 26; c++) {
            if (l[c] == -1) continue;

            int a = f[c], b = l[c];
            bool ok = true;

            for (int i = a; i <= b; i++) {
                int x = s[i] - 'a';

                if (f[x] < a) {
                    ok = false;
                    break;
                }

                b = max(b, l[x]);
            }

            if (ok)
                v.push_back({a, b});
        }

        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for (pair<int,int> p : v) {
            if (p.first > end) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                end = p.second;
            }
        }

        return ans;
    }
};