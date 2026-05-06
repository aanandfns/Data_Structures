class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();

        for(int i=0; i<n; i++) {
            int wh = m;
            for(int j=m-1; j >= 0; j--) {
                if(g[i][j] == '*') {
                    wh = j;
                } else if(g[i][j] == '#') {
                    wh--;
                    swap(g[i][j], g[i][wh]);
                }
            }
        }

        vector<vector<char>> ans(m);
        for(int k=0; k<m; k++) {
            for(int i=n-1; i>=0; i--) {
                ans[k].push_back(g[i][k]);
            }
        }

        return ans;
    }
};