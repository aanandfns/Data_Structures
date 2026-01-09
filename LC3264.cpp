class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        while(k--) {
            auto val = min_element(nums.begin(), nums.end());
            *val = *val * multi;
        }

        return nums;
    }
};