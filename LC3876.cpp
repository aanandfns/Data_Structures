class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int i=0; i<n; i++) if(nums[i]&1) cnt++;

        if(cnt == n || cnt == 0) return true;

        sort(nums.begin(), nums.end());
        int val = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] & 1) {
                val = nums[i];
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(nums[i] % 2 == 0) {
                if(nums[i] < val + 1) {
                    return false;
                }
            }
        }

        return true;
    }
};