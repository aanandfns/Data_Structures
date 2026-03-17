class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        map<int, int> mpp;
        for(int i=0; i<n; i++) mpp[nums[i]]++;

        int ans = INT_MIN;
        int cur = 1;
        int prev = -1;
        auto temp = mpp.begin();
        int first = temp->first;
        for(auto it : mpp) {
            if(it.first == first) {
                prev = it.first;
                continue;
            }

            if(it.first - prev == 1) {
                cur++;
            } else {
                ans = max(cur, ans);
                cur = 1;
            }
            prev = it.first;
        }
        ans = max(cur, ans);

        return ans;
    }
};