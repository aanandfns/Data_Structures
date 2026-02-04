class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int x = target.size();

        int val = 1;
        for(int i=0; i<x; i++) {
            while(val != target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                val++;
            }

            if(target[i] == val) ans.push_back("Push");
            val++;
        }

        return ans;
    }
};