class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        vector<pair<int, char>> p(n);

        for(int i=0; i<n; i++) {
            p[i] = {indices[i] , s[i]};
        }

        sort(p.begin(), p.end());
        string ans = "";
        for(int i=0; i<n; i++) {
            ans += p[i].second;
        }

        return ans;
    }
};