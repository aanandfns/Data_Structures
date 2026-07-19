class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};

        vector<vector<int>> ans = {{1}};
        for(int i=1; i<numRows; i++) {
            vector<int> cur = {1};
            for(int j=1; j<ans[i-1].size(); j++) {
                cur.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            cur.push_back(1);
            ans.push_back(cur);
        }

        return ans;
    }
};