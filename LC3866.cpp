class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        int ans = -1;
        for(int i=0; i<n; i++) {
            if(nums[i]%2 == 0) {
                if(mp[nums[i]] == 1) {
                    return nums[i];
                }
            }
        }

        return ans;
    }
};