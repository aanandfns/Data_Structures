class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();

        set<long long> s;
        for(int i=0; i<n; i++) s.insert(nums[i]);

        for(int i=0; i<n; i++) {
            long long num = nums[i];

            for(int j=1; j*j <= num; j++) {
                if(num%j == 0) {
                    long long v1 = j;
                    long long v2 = num / j;

                    if(s.count(v1) && s.count(v2)) {
                        nums[i] = v1;
                        break;
                    }
                    else if(s.count(v1)) {
                        nums[i] = v1;
                        break;
                    }
                    else if(s.count(v2)) {
                        nums[i] = v2;
                    }
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<n; i++) ans += nums[i];

        return ans;
    }
};