class Solution {
public:
    string s;
    int pos;

    set<string> merge(set<string> a, set<string> b) {
        set<string> res;

        for(string x : a)
            for(string y : b)
                res.insert(x + y);

        return res;
    }

    set<string> expression() {
        set<string> res = sequence();

        while(pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> cur = sequence();

            for(string x : cur)
                res.insert(x);
        }

        return res;
    }

    set<string> sequence() {
        set<string> res;
        res.insert("");

        while(pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur;

            if(s[pos] == '{') {
                pos++;
                cur = expression();
                pos++;
            }
            else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            res = merge(res, cur);
        }

        return res;
    }

    vector<string> braceExpansionII(string str) {
        s = str;
        pos = 0;

        set<string> ans = expression();

        return vector<string>(ans.begin(), ans.end());
    }
};