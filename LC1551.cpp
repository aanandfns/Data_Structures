class Solution {
public:
    int minOperations(int n) {
        int val;
        if(n&1) val = 2 * (n/2) + 1;
        else val = ((2 * (n/2) + 1) + (2 * (n/2 - 1) + 1)) / 2;

        int ans = 0;
        for(int i=1; i<=n/2; i++) ans += abs(((2*i)-1) - val);

        return ans;
    }
};