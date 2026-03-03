class Solution {
public:
    string rev(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string invert(string s) {
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }

        return s;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        string sNext = "";
        for(int i=1; i<=n; i++) {
            sNext = s + "1" + rev(invert(s));
            s = sNext;
        }

        return sNext[k-1];
    }
};