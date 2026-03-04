class Solution {
public:
    bool chk(int row, int col, int n, int m, vector<vector<int>>& mat) {
        for(int i=0; i<n; i++) {
            if(i == row) continue;
            if(mat[i][col] == 1) return 0;
        }

        for(int i=0; i<m; i++) {
            if(i == col) continue;
            if(mat[row][i] == 1) return 0;
        }

        return 1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) {
                    if(chk(i, j, n, m, mat)) ans++;
                }
            }
        }

        return ans;
    }
};