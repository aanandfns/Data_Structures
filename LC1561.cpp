class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int j = n-2;
        int ans = 0;
        int val = n / 3;
        while(val--) {
            ans += piles[j];
            j -= 2;
        }
        return ans;

    }
};