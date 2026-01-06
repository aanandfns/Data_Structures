class Solution {
public:
    int subtractProductAndSum(int n) {
        long long prod = 1;
        long long sum = 0;
        while(n != 0) {
            long long rem = n % 10;
            prod *= rem;
            sum += rem;
            n /= 10;
        }
        return prod - sum;
    }
};