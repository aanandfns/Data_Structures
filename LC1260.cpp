class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> v;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                v.push_back(grid[i][j]);
            }
        }

        int x = v.size();
        vector<int> nw(x);
        for(int i=0; i<x; i++) {
            nw[(i+k)%x] = v[i];
        }

        int idx = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                grid[i][j] = nw[idx++];
            }
        }

        return grid;
    }
};