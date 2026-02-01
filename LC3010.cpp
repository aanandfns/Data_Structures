// Brute Force
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        for(int i=1; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int val = nums[0] + nums[i] + nums[j];
                ans = min(ans, val);
            }

        }

        return ans;
    }
};

// optimal
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin()+1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};