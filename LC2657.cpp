// Brute Force ~ TC : O(n^2) ~ SC : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            unordered_set<int> s;
            for(int j=i; j>=0; j--) s.insert(A[j]);

            int cnt = 0;
            for(int j=i; j>=0; j--) {
                if(s.find(B[j]) != s.end()) cnt++;
            }

            ans[i] = cnt;
        }

        return ans;

    }
};

// OPTIMAL ~ TC : O(N) ~ SC : (N)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n), freq(n+1, 0);

        int cnt = 0;
        for(int i=0; i<n; i++) {
            freq[A[i]]++;
            freq[B[i]]++;

            if(A[i] == B[i] && freq[A[i]] == 2) cnt++;
            else {
                if(freq[A[i]] == 2) cnt++;
                if(freq[B[i]] == 2) cnt++;
            }

            ans[i] = cnt;
        }

        return ans;
    }
};