class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = n;
        
        while(ans) {
            int prod = 1;
            int val = ans;
            while(val) {
                int rem = val % 10;
                prod *= rem;
                val /= 10;
            }
            if(prod % t == 0) return ans;
            ans++;
        }

        return -1;
    }
};