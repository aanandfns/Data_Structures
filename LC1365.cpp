// TC : O(n ^ 2)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] > nums[j]) ans[i]++;
                else if(nums[i] < nums[j]) ans[j]++;
            }
        }

        return ans;
    }
};
