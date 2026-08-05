class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        
        int cg = INT_MIN;
        for(int i=0; i<n; i++) {
            cg = max(cg, candies[i]);
        }

        vector<bool> ans(n);
        for(int i=0; i<n; i++) {
            if(candies[i] + extraCandies >= cg) {
                ans[i] = 1;
            }
        }

        return ans;
    }
};