class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == ')') {

                if(st.empty()) st.push(s[i]);
                else {
                    if(st.top() != s[i]) st.pop();
                    else st.push(s[i]);
                }

                ans = max(ans, (int)st.size());
            }
        }

        return ans;
    }
};