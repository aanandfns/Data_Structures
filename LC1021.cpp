class Solution {
public:
    string removeOuterParentheses(string s) {
        int i = 0;
        stack<int> st;
        string ans;
        while(i < s.size()) {
            st.push(s[i++]);
            while(!st.empty()) {
                if(st.top() == s[i]) st.push(s[i]);
                else st.pop();

                if(!st.empty()) ans += s[i++];
            }
            i++;
        }
        return ans;
    }
};