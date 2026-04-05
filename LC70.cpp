class Solution {
public:
    int func(int n, vector<int>& arr) {
        if(n <= 1) return 1;

        if(arr[n] != -1) return arr[n];

        arr[n] = func(n-1, arr) + func(n-2, arr);
        return arr[n];
    }
    int climbStairs(int n) {
        vector<int> arr(n+5, -1);

        return func(n, arr);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;

        int p1 = 3;
        int p2 = 2;

        int ans;
        for(int i=4; i<=n; i++) {
            ans = p1 + p2;
            p2 = p1;
            p1 = ans;
        }

        return ans;
    }
};