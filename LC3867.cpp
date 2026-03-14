class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> pGcd;
        int n= nums.size();

        long long mx = LLONG_MIN;
        for(int i=0; i<n; i++) {
            mx = max(mx, (long long) nums[i]);
            pGcd.push_back(gcd(nums[i], mx));
        }

        sort(pGcd.begin(), pGcd.end());
        
        int i = 0;
        int j = pGcd.size() - 1;
        long long ans = 0;
        while(i < j) {
            ans += gcd(pGcd[i], pGcd[j]);
            i++; j--;
        }

        return ans;
    }
};