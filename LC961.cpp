class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for(int val : nums) {
            if(s.find(val) != s.end()) return val;
            else s.insert(val);
        }

        return -1;
    }
};