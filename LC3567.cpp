class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, INT_MAX));


        for(int sr=0; sr<n-k+1; sr++) {
            for(int sc=0; sc<m-k+1; sc++) {

                set<int> s;
                for(int i=sr; i<sr+k; i++) {
                    for(int j=sc; j<sc+k; j++) {
                        s.insert(grid[i][j]);
                    }
                }

                for(auto it : s) {
                    for(auto x : s) {
                        if(it == x) continue;
                        ans[sr][sc] = min(ans[sr][sc], abs(it - x));
                    }
                }

                if(s.size() == 1) ans[sr][sc] = 0;
            }
        }

        return ans;
    }
};