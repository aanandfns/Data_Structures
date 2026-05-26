class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> a(26, 0);
        vector<int> A(26, 0);

        int n = s.size();
        for(int i=0; i<n; i++) {
            if(isupper(s[i])) {
                A[s[i] - 'A']++;
            } else {
                a[s[i] - 'a']++;
            }
        }

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(a[i] > 0 && A[i] > 0) ans++;
        }

        return ans;
    }
};