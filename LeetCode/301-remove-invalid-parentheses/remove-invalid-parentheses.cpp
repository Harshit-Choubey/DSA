class Solution {
public:
    vector<string> ans;

    void solve(string s, int start, int removeStart, char a, char b) {
        int balance = 0;

        for(int i = start; i < s.size(); i++) {
            if(s[i] == a)
                balance++;
            else if(s[i] == b)
                balance--;

            if(balance < 0) {
                for(int j = removeStart; j <= i; j++) {
                    if(s[j] == b && (j == removeStart || s[j-1] != b))
                        solve(s.substr(0,j) + s.substr(j+1), i, j, a, b);
                }
                return;
            }
        }

        reverse(s.begin(), s.end());

        if(a == '(')
            solve(s, 0, 0, ')', '(');
        else
            ans.push_back(s);
    }

    vector<string> removeInvalidParentheses(string s) {
        solve(s, 0, 0, '(', ')');
        return ans;
    }
};