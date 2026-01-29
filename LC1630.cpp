class Solution {
public:
    bool chk(vector<int> temp) {
        for(int i=0; i<temp.size()-1; i++) {
            if(temp[i+1] - temp[i] != temp[1] - temp[0]) return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n);
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int j=l[i]; j<=r[i]; j++) {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            ans[i] = chk(temp);
        }

        return ans;
    }
};