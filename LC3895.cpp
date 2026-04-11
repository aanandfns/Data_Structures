class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            int val = nums[i];

            while(val > 0) {
                if(val%10 == digit) ans++;
                val /= 10;
            }
        }

        return ans;
    }
};