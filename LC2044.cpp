class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans) {
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(nums, i+1, temp, ans);
        temp.pop_back();
        helper(nums, i+1, temp, ans);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, 0, temp, ans);

        int a = -1;
        vector<int> maxi;
        for(int i=0; i<ans.size(); i++) {
            int val = 0;
            for(int j=0; j<ans[i].size(); j++) {
                val |= ans[i][j];
            }
            maxi.push_back(val);
            a = max(a, val);
        }

        int cnt = 0;
        for(int i=0; i<maxi.size(); i++) {
            if(a == maxi[i]) cnt++;
        }

        return cnt;
    }
};