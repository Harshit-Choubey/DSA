class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;

        for(char c : s) {
            if(c != ')') {
                st.push_back(c);
            }
            else {
                string temp = "";

                while(st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }

                st.pop_back();

                for(char x : temp)
                    st.push_back(x);
            }
        }

        return string(st.begin(), st.end());
    }
};