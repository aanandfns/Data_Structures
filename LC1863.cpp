class Solution {
public:
    void subsets(vector<int>& nums, int idx, vector<int> temp, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        subsets(nums, idx+1, temp, ans);
        temp.pop_back();
        subsets(nums, idx+1, temp, ans);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        subsets(nums, 0, temp, ans);

        int fans = 0;
        for(int i=0; i<ans.size(); i++) {
            int val = 0;
            for(int j=0; j<ans[i].size(); j++) {
                val ^= ans[i][j];
            }
            fans += val;
        }

        return fans;
    }
};