class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> v(102);

        int n = nums.size();
        for(int i=0; i<n; i++) {
            v[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(int i=0; i<102; i++) {
            if(v[i].size() < 3) continue;

            for(int j=0; j<v[i].size()-2; j++) {
                int dist = abs(v[i][j] - v[i][j+1]) + abs(v[i][j] - v[i][j+2]) + abs(v[i][j+1] - v[i][j+2]);
                ans = min(ans, dist);
            }
        }

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};