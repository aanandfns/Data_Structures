class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int st = x;
        int end = x + k - 1;
        for(int j=y; j<y+k; j++) {
            int m = st;
            int n = end;
            while(m < n) {
                swap(grid[m++][j], grid[n--][j]);
            }
        }

        return grid;
    }
};