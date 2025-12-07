// Brute Force ~ O(n)
class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++) {
            if(i&1) cnt++;
        }
        return cnt;
    }
};

// TC : O(n)
class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        int val = high - low + 1;

        if((low&1) && (val&1)) return val/2 + 1;
        else return val/2;
    }
};