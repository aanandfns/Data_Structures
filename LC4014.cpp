class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        int n = p.size();
        int m = d.size();

        sort(d.rbegin(), d.rend());
        sort(p.rbegin(), p.rend());

        double ans = 0;
        for(int i=0; i<min(m, n); i++) {
            ans += (double)(p[i] * (100 - d[i])) / 100;
        }

        for(int i=min(n, m); i<n; i++) ans += p[i];

        return ans;
    }
};