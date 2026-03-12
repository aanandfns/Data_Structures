class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowOne;
        vector<int> colOne;
        for(int i=0; i<m; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) cnt++;
            }
            rowOne.push_back(cnt);
        }

        for(int j=0; j<n; j++) {
            int cnt = 0;
            for(int i=0; i<m; i++) {
                if(grid[i][j] == 1) cnt++;
            }
            colOne.push_back(cnt);
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = 2*rowOne[i] + 2*colOne[j] - n - m;
            }
        }

        return ans;
    }
};