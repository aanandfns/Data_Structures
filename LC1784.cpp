class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ok = 0;
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') cnt++;
        }
        
        if(cnt == 1) return true;

        int mx = INT_MIN;
        int cur = 0;
        for(int i=0; i<n; i++) {
            if(cur == 0 && s[i] == '0') continue;
            
            if(s[i] == '1') cur++;
            else break;
        }

        return cur == cnt;
    }
};