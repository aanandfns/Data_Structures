class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            vector<int> temp;
            while(nums[i] > 0) {
                temp.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
            while(temp.size() > 0) {
                ans.push_back(temp.back());
                temp.pop_back();
            }
        }

        return ans;
    }
};