class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        int st = to_string(low).size();
        int end = to_string(high).size();

        vector<int> ans;
        for(int i=st; i <= end; i++) {
            for(int j=0; j <= 9 - i; j++) {
                int val = stoi(s.substr(j, i));
                if(low <= val && val <= high) ans.push_back(val);
            }
        }

        return ans;
    }
};