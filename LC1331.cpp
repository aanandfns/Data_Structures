class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        for(int i=0; i<n; i++) mp[arr[i]]++;
        
        int val = 1;
        for(auto &it : mp) {
            it.second = val;
            val++;
        }

        for(int i=0; i<n; i++) arr[i] = mp[arr[i]];
        return arr;
    }
};