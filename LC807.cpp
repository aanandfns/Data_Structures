// TC -> O(N ^ 3)
class Solution {
public:
    int value(vector<vector<int>>& grid, int i, int j) {
        int rowMax = INT_MIN;
        for(int k = 0; k < grid.size(); k++) {
            rowMax = max(rowMax , grid[k][j]);
        }

        int colMax = INT_MIN;
        for(int k=0; k<grid.size(); k++) {
            colMax = max(colMax, grid[i][k]);
        }

        return min(rowMax, colMax);
    }

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans += value(grid, i, j) - grid[i][j];
            }
        }

        return ans;
    }
};

// TC : O(N^2)
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n);
        vector<int> col(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[i] = max(col[i], grid[j][i]);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }

        return ans;

    }
};