class Solution {
public:
    int passwordStrength(string s) {
        set<char> st = {'!', '@', '#', '$'};
        vector<int> hashSmall(26, 0);
        vector<int> hashLarge(26, 0);
        vector<int> hashNum(10, 0);
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if('a' <= s[i] && s[i] <= 'z' && !hashSmall[s[i] - 'a']) {
                ans += 1;
                hashSmall[s[i] - 'a'] = 1;
            } else if('A' <= s[i] && s[i] <= 'Z' && !hashLarge[s[i] - 'A']) {
                ans += 2;
                hashLarge[s[i] - 'A'] = 1;
            } else if('0' <= s[i] && s[i] <= '9' && !hashNum[s[i] - '0']) {
                ans += 3;
                hashNum[s[i] - '0'] = 1;
            } else if (st.count(s[i])) {
                ans += 5;
                st.erase(s[i]);
            }
        }

        return ans;
    }
};