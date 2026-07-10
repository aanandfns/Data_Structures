class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n, nums[n-1]);
        for(int i=n-2; i>=0; i--) mx[i] = max(mx[i+1], nums[i]);

        int ans = INT_MIN;
        for(int i=0; i<n-k; i++) {
            ans = max(ans, nums[i] + mx[i+k]);
        }

        return ans;
    }
};