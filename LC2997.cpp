class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) xr ^= nums[i];

        int ans = 0;
        while(k != 0 || xr != 0) {
            if(k % 2 != xr % 2) ans++;
            k >>= 1;
            xr >>= 1;
        }

        return ans;
    }
};