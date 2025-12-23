class Solution {
public:
    int maxDistinct(string s) {
        if(s.size() == 1) return 1;
        unordered_set<char> st;
        int ans = 0;
        st.insert(s[0]);

        for(int i=1; i<s.size(); i++) {
            if(s[i] != s[i-1] && st.find(s[i]) == st.end()) {
                ans++;
                st.insert(s[i]);
            }
        }

        return ans+1;
    }
};