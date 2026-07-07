//Brute Force
// TC : O(n ^ 2)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));

        int val = 1;
        for(int k=0; k<(n+1)/2; k++) {
            for(int j=0; j<n; j++) {
                if(v[k][j] == 0) v[k][j] = val++;
            }

            for(int i=0; i<n; i++) {
                if(v[i][n-1-k] == 0) v[i][n-1-k] = val++;
            }

            for(int j=n-1; j>=0; j--) {
                if(v[n-1-k][j] == 0) v[n-1-k][j] = val++;
            }

            for(int i=n-1; i>=0; i--) {
                if(v[i][k] == 0) v[i][k] = val++;
            }
        }

        return v;
    }
};


// Slightly Optimized
// TC : O(n ^ 2)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));

        int val = 1;
        int layer = 0;
        for(int k=0; k<(n+1)/2; k++) {
            for(int j=layer; j<n-layer; j++) {
                if(v[k][j] == 0) v[k][j] = val++;
            }

            for(int i=layer; i<n-layer; i++) {
                if(v[i][n-1-k] == 0) v[i][n-1-k] = val++;
            }

            for(int j=n-1-layer; j>=layer; j--) {
                if(v[n-1-k][j] == 0) v[n-1-k][j] = val++;
            }

            for(int i=n-1-layer; i>=layer; i--) {
                if(v[i][k] == 0) v[i][k] = val++;
            }

            layer++;
        }

        return v;
    }
};