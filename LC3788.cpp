class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> prefixSum(n,0);

        long long val = 0;
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i]; 
        }

        vector<long long> suffixMin(n);
        // long long mn = nums[n-1];

        suffixMin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            // suffixMin[i] = min( (long long) nums[i+1] , mn);
            // mn = suffixMin[i];

            suffixMin[i] = min( (long long) nums[i+1] , suffixMin[i+1]);
        }

        long long ans = LONG_MIN;
        for(int i=0; i<n-1; i++) {
            ans = max(ans, prefixSum[i] - suffixMin[i]);
        }

        return ans;
    }
};