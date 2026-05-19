class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        for(auto it : s1) {
            if(s2.count(it)) {
                return it;
            }
        }

        return -1;
    }
};