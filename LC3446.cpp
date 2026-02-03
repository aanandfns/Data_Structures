class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i=1; i<n; i++) {
            int row = 0;
            int col = i;
            vector<int> temp;
            while(row < n && col < n) {
                temp.push_back(grid[row++][col++]);
            }
            sort(temp.begin(), temp.end());

            row = 0;
            col = i;
            int idx = 0;
            while(row < n && col < n) {
                grid[row++][col++] = temp[idx++];
            }
            temp.clear();
        }

        for(int i=0; i<n; i++) {
            int row = i;
            int col = 0;
            vector<int> temp;
            while(row < n && col < n) {
                temp.push_back(grid[row++][col++]);
            }
            sort(temp.rbegin(), temp.rend());

            row = 0;
            col = i;
            int idx = 0;
            while(row < n && col < n) {
                grid[row++][col++] = temp[idx++];
            }
            temp.clear();
        }

        return grid;
    }
};