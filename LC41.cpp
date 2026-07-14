class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i=0; i<n; i++) if(nums[i] > 0) s.insert(nums[i]);

        int ans = 1;
        for(auto it : s) {
            if(it == ans) ans++;
            else return ans;
        }

        return ans;
    }
};