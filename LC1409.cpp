class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        int n = q.size();
        vector<int> ans(n, 0);

        vector<int> p(m);
        for(int i=0; i<m; i++) p[i] = i+1;

        for(int i=0; i<n; i++) {
            int idx = 0;
            int val = q[i];
            for(int j=0; j<m; j++) {
                if(p[j] == val) {
                    idx = j;
                }
            }

            ans[i] = idx;
            for(int j=idx-1; j>=0; j--) {
                p[j+1] = p[j];
            }
            p[0] = val;
        }

        return ans;
    }
};