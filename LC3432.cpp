class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int pSum = 0;
        int sum = 0;
        for(int val : nums) sum += val;
        if(sum&1) return 0;

        int left = 0, right = sum;
        // <n-1 because : if we goo till <n then oure right subarray will be empty
        for(int i=0; i<n-1; i++) {
            left += nums[i];
            right -= nums[i];
            if(abs(left - right) % 2 == 0) ans++;
        }

        return ans;
    }
};