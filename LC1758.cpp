// using extra space O(n);
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string s1 = "0";
        string s2 = "1";
        for(int i=1; i<n; i++) {
            if(s1.back() == '0') s1 += '1';
            else s1 += '0';

            if(s2.back() == '0') s2 += '1';
            else s2 += '0';
        }

        int ans1 = 0;
        int ans2 = 0;
        for(int i=0; i<n; i++) {
            if(s[i] != s1[i]) ans1++;
            if(s[i] != s2[i]) ans2++;
        }

        return min(ans1, ans2);
    }
};

// without extra space
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string s1 = s;
        int ans1 = 0;
        for(int i=1; i<n; i++) {
            if(s1[i-1] == s1[i]) {
                ans1++;
                if(s1[i] == '0') s1[i] = '1';
                else s1[i] = '0';
            }
        }

        string s2 = s;
        int ans2 = 1;
        if(s2[0] == '0') s2[0] = '1';
        else s2[0] = '0';
        for(int i=1; i<n; i++) {
            if(s2[i-1] == s2[i]) {
                ans2++;
                if(s2[i] == '0') s2[i] = '1';
                else s2[i] = '0';
            }
        }

        return min(ans1, ans2);
    }
};