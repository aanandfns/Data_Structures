class Solution {
public:
    bool consecutiveSetBits(int n) {
        string s = "";
        while(n > 0) {
            if(n&1) s += '1';
            else s += '0';
            n >>= 1;
        }

        int cnt = 0;
        if(s.size() > 1) {
            for(int i=0; i<s.size()-1; i++) {
               if(s[i] == s[i+1] && s[i] == '1') cnt++;
            }
        }

        return cnt == 1;
    }
};