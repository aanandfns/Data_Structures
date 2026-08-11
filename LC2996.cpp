class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        
        int fin = 0;
        int i = 1;
        while(i < n && nums[i-1] + 1 == nums[i]) i++;
        for(int j=0; j<i; j++) fin += nums[j];

        set<int> s(nums.begin(), nums.end());
        while(s.count(fin)) fin++;

        return fin;
    }
};    