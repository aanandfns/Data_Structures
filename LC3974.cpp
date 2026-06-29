class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());

        long long ans = 0;
        for(int i=0; i<k; i++) {
            ans += 1LL * max(1, mul) * nums[i];
            mul--;
        }

        return ans;
    }
};