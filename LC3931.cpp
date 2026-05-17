class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        bool ok = 1;
        for(int i=1; i<n; i++) {
            if(abs(s[i-1] - s[i]) > 2) {
                ok = 0;
                break;
            }
        }

        if(ok) return 1;
        else return 0;
    }
};