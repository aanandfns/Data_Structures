class Solution {
public:
    long long sumAndMultiply(int n) {
        int num  = 0;
        int sum = 0;
        while(n != 0) {
            if(n%10 == 0) {
                n = n/10;
                continue;
            } else {
                int remain = n%10;
                num = num*10 + remain;
                sum += remain;
                n = n/10;
            }
        }
        int x = num;
            int rev = 0;
            while(x != 0) {
                int remain = x%10;
                rev = rev*10 + remain;
                x /= 10;
            }
        return 1LL*rev * sum;
    }
};