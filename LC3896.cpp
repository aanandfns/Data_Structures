class Solution {
public:
    bool isPrime(int x) {
        if(x < 2) return false;
        for(int i = 2; i * i <= x; i++) if (x % i == 0) return false;
        return true;
    }

    int nextNotPrime(int n) {
        while (true) {
            if (!isPrime(n)) return n;
            n++;
        }
    }
    
    int nextPrime(int n) {
        while(true) {
            if (isPrime(n)) return n;
            n++;
        }
    }
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i&1) {
                ans += abs(nums[i] - nextNotPrime(nums[i]));
            } else {
                ans += abs(nums[i] - nextPrime(nums[i]));
            }
        }

        return ans;
    }
};