// TC : O(N log N) ~ SC : O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = INT_MIN;
        sort(begin(nums), end(nums));
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            int sum = nums[i++] + nums[j--];
            ans = max(sum, ans);
        }
        return ans;
    }
};