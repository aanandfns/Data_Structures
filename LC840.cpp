class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& grid) {
        unordered_set<int> s;

        // To check the range
        for(int i=row; i<row+3; i++) {
            for(int j=col; j<col+3; j++) {
                if(grid[i][j] < 1 || 9 < grid[i][j]) return 0;

                s.insert(grid[i][j]);
                if(grid[i][j] > 9) return 0;
            }
        }

        // to check if there is 1 to 9 or not
        if(s.size() != 9) return 0;


        // checking diagonals
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];
        if(diag1 != diag2) return 0;

        int sum = 0;
        // checking rows
        for(int i=row; i<row+3; i++) {
            for(int j=col; j<col+3; j++) {
                sum += grid[i][j];
            }

            if(sum != diag1) return 0;
            sum = 0;
        }

        // checking columns
        for(int i=col; i<col+3; i++) {
            for(int j=row; j<row+3; j++) {
                sum += grid[j][i];
            }

            if(sum != diag1) return 0;
            sum = 0;
        }

        return 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // for traversal 
        int row = grid.size() - 3;
        int col = grid[0].size() - 3;

        int ans = 0;
        for(int i=0; i<=row; i++) {
            for(int j=0; j<=col; j++) {
                ans += helper(i, j, grid);
            }
        }

        return ans;

    }
};