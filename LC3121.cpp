class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> a(26, 0);
        vector<int> A(26, 0);

        int n = word.size();
        for(int i=0; i<n; i++) {
            if(isupper(word[i])) {
                A[word[i] - 'A']++;
            } else {
                a[word[i] - 'a']++;
            }
        }

        vector<int> idx(26, -1);
        for(int i=0; i<n; i++) {
            if(islower(word[i])) idx[word[i]-'a'] = i;
        }

        vector<int> idxA(26, -1);
        for(int i=n-1; i>=0; i--) {
            if(isupper(word[i])) idxA[word[i]-'A'] = i;
        }

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(a[i] > 0 && A[i] > 0) {
                if(idxA[i] > idx[i]) ans++;   
            }
        }

        return ans;
    }
};