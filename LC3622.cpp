class Solution {
public:
    bool checkDivisibility(int n) {
        int val = n;
        int sum = 0;
        while(val != 0) {
            sum += val % 10;
            val /= 10;
        }
        int prod = 1;
        val = n;
        while(val != 0) {
            prod *= val % 10;
            val /= 10;
        }

        return n % (prod + sum) == 0;
    }
};