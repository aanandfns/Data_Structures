class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> closest(n);
        for(int i=0; i<n; i++) {
            if(i == 0) closest[i] = 1;
            else if(i == n-1) closest[i] = n-2;
            else {
                if(abs(nums[i] - nums[i-1]) <= abs(nums[i] - nums[i+1])) {
                    closest[i] = i-1;
                } else closest[i] = i+1;
            }
        }

        vector<int> pSum(n, 0);
        vector<int> sSum(n, 0);

        for(int i=1; i<n; i++) {
            if(closest[i-1] == i) pSum[i] = pSum[i-1] + 1;
            else pSum[i] = pSum[i-1] + abs(nums[i] - nums[i-1]);
        }

        for(int i=n-2; i>=0; i--) {
            if(closest[i+1] == i) sSum[i] = sSum[i+1] + 1;
            else sSum[i] = sSum[i+1] + abs(nums[i] - nums[i+1]);
        }

        int x = queries.size();
        vector<int> ans(x, -1);
        for(int i=0; i<x; i++) {
            if(queries[i][0] <= queries[i][1]) {
                ans[i] = pSum[queries[i][1]] - pSum[queries[i][0]];
            } else {
                ans[i] = sSum[queries[i][1]] - sSum[queries[i][0]];
            }
        }

        return ans;
    }
};