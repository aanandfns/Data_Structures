class Solution {
public:
    void helper(int n, string s, vector<string>& ans) {
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }
        helper(n, s + '0', ans);
        helper(n, s + '1', ans);
    }

    vector<string> generateValidStrings(int n, int k) {
        if(n == 1) return {"1", "0"};

        vector<string> ans;
        helper(n, "", ans);

        vector<string> fn;
        for(auto it : ans) {
            string s = it;

            int cnt = 0;
            for(int i=0; i<n; i++) if(s[i] == '1') cnt += i;

            bool ok = 1;
            for(int i=0; i<n-1; i++) {
                if(s[i] == s[i+1] && s[i] == '1') {
                    ok = 0;
                    break;
                }
            }

            if(ok && cnt <= k) fn.push_back(s);
        }

        return fn;
    }
};