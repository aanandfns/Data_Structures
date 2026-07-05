//Brute Force
// TC:- O(n ^ 3) ans SC : O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int cur = 1e8;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k = j+1; k<n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(abs(target - sum) < cur) {
                        ans = sum;
                        cur = abs(target - sum);
                    }
                }
            }
        }

        return ans;
    }
};

// Optimized
// TC : O(n ^ 2) and SC : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;
        int cur = 1e8;

        for(int i=0; i<n-2; i++) {
            int left = i+1;
            int right = n-1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < cur) {
                    ans = sum;
                    cur = abs(sum - target);
                }

                if(sum < target) left++;
                else if(sum > target) right--;
                else return ans;
            }
        }

        return ans;
    }
};