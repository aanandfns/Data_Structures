class Solution {
public:
    void helper(set<string>& s, string& temp, string& ans) {
        if(temp.size() == s.size()) {
            if(s.find(temp) == s.end()) {  
                ans = temp;
            }
            return;
        }

        temp += '1';
        helper(s, temp, ans);
        temp.pop_back();
        temp += '0';
        helper(s, temp, ans);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        for(int i=0; i<nums.size(); i++) s.insert(nums[i]);
        string ans = "";
        string temp = "";
        helper(s, temp, ans);

        return ans;
    }
};