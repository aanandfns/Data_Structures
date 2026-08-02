// Using Recursion Backtracking
// TC : O(2 ^ n)
// SC : O(N)
class Solution {
public:
    bool helper(vector<int>& nums, int low, int high, bool ok, int p1, int p2) {
        if(low > high) return p1 >= p2;

        if(ok) {
            if(helper(nums, low+1, high, 1-ok, p1+nums[low], p2)) return 1;
            else if(helper(nums, low, high-1, 1-ok, p1+nums[high], p2)) return 1;
            else return 0;
        } else {
            if(!helper(nums, low+1, high, 1-ok, p1, p2+nums[low])) return 0;
            else if(!helper(nums, low, high-1, 1-ok, p1, p2+nums[high])) return 0;
            else return 1;
        }

        return 0;
    }

    bool predictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1, 1, 0, 0);
    }
};

// Can be Enhanced by DP / memoization with expected TC : O(N ^ 2) and SC : (N ^ 2)