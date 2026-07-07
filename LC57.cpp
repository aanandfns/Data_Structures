class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& itv, vector<int>& nitv) {
        itv.push_back(nitv);
        sort(itv.begin(), itv.end());
        int n = itv.size();

        vector<int> cur = itv[0];
        vector<vector<int>> ans;
        for(int i=1; i<n; i++) {
            if(itv[i][0] <= cur[1]) {
                cur[0] = min(cur[0], itv[i][0]);
                cur[1] = max(cur[1], itv[i][1]);
            } else {
                ans.push_back(cur);
                cur = itv[i];
            }
        }
        ans.push_back(cur);

        return ans;
    }
};