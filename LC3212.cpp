class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<int, int>>> ans(n, vector<pair<int, int>>(m, {0, 0}));

        for(int i=0; i<n; i++) {
            int x = 0;
            int y = 0;
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'X') x++;
                else if(grid[i][j] == 'Y') y++;

                ans[i][j].first += x;
                ans[i][j].second += y;
            }
        }

        for(int j=0; j<m; j++) {
            for(int i=1; i<n; i++) {
                ans[i][j].first += ans[i-1][j].first;
                ans[i][j].second += ans[i-1][j].second; 
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(ans[i][j].first == ans[i][j].second && ans[i][j].first != 0) cnt++;
            }
        }

        return cnt;
    }
};  