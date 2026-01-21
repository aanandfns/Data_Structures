class Solution {
public:
    bool dist(vector<int> p, vector<int> c) {
        int dx = p[0] - c[0];
        int dy = p[1] - c[1];
        return dx*dx + dy*dy <= c[2]*c[2];
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int> c : queries) {
            int cnt = 0;
            for(vector<int> p : points) {
                if(dist(p, c)) cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};