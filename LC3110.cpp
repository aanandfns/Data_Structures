class Solution {
public:
    int scoreOfString(string s) {
        int val = 0;
        for(int i=0; i<s.size()-1; i++) {
            val += abs(s[i] - s[i+1]);
        }
        return val;
    }
};