class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        sort(itv.begin(), itv.end());

        vector<vector<int>> ans;
        vector<int> prev = itv[0];
        vector<int> merged = itv[0];

        for(int i=1; i<itv.size(); i++) {
            if(prev[1] >= itv[i][0]) {
                merged[0] = min(prev[0], itv[i][0]);
                merged[1] = max(prev[1], itv[i][1]);
                prev = merged;
            } else {
                ans.push_back(prev);
                prev = itv[i]; // after pushing prev in the above line, we have to update the next value of prev
                // Which is going to be the current pair of numbers
            }
        }
        ans.push_back(prev);
        return ans;
    }
};