class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& v) {
        sort(begin(v), end(v));
        int n = v.size();

        int mn = INT_MAX;
        for(int i=0; i<n-1; i++) mn = min(mn, abs(v[i] - v[i+1]));

        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++) {
            if(v[i+1] - v[i] == mn) ans.push_back({v[i], v[i+1]});
        }

        return ans;
        
    }
};