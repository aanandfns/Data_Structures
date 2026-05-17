class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;

        int ans = 0;
        for(int i=0; i<40000; i++) {
            int x = k;
            int val = 1;
            while(x--) val = val * i;
            if(val > r) break;

            if(val >= l && val <= r) ans++;
        }

        return ans;
    }
};