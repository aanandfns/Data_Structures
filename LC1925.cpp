// TC : O(n^2 * Log n)
class Solution {
public:
    int check(int n) {
        int low = 1;
        int high = n;
        while(low <= high) {
            int mid = low + (high - low)/2;

            long long val = 1LL * mid * mid;
            if(val > n) high = mid - 1;
            else if(val < n) low = mid + 1;
            else return mid;
        }
        return -1;
    }

    int countTriples(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j) continue;
                int val = i*i + j*j;
                int c = check(val);
                if(c > 0 && c <= n && c*c == val) ans++;
            }
        }
        return ans;
    }
};

// TC : O(n^2)
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j) continue;
                int val = i*i + j*j;
                int c = sqrt(val + 1);
                if(c<=n && c*c == val) ans++;
            }
        }
        return ans;
    }
};