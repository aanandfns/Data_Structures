class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for(int i=1; i<=n; i++) pre[i] = pre[i-1] + nums[i-1];

        int ans = 0;
        for(int i=0; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                long long sum = pre[j] - pre[i];
                if(sum != 0) {
                    int dig = log10(sum);
                    int val = sum / (long long)pow(10, dig);
                    if(sum%10 == x && val == x) ans++;
                }
            }
        }

        return ans;
    }
};