class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> freq(n, 0);

        for(int i=0; i<n; i++) {
            if(freq[i] == 1) continue;

            vector<int> temp;
            unordered_set<int> s;

            temp.push_back(nums[i]);
            s.insert(nums[i]);

            freq[i] = 1;

            for(int j=0; j<n; j++) {
                if(freq[j] == 0 && s.find(nums[j]) == s.end()) {
                    freq[j] = 1;
                    s.insert(nums[j]);
                    temp.push_back(nums[j]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};