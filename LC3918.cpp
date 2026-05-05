class Solution {
public:
    bool chk(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        for(int i=2; i*i<=n; i++) {
            if(n%i == 0) return 0;
        }
        return 1;
    }

    int sumOfPrimesInRange(int n) {
        int rev = 0;
        int temp = n;
        while(temp != 0) {
            rev = rev * 10 + (temp%10);
            temp /= 10; 
        }

        int ans = 0;
        for(int i=min(rev, n); i <= max(rev, n); i++) {
            if(chk(i)) ans += i;
        }

        return ans;
    }
};