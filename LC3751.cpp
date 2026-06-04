class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int j=num1; j<=num2; j++) {
            string s = to_string(j);

            int n = s.size();
            if(n < 3) continue;
            for(int i=1; i<n-1; i++) {
                if(s[i-1] < s[i] && s[i] > s[i+1]) ans++;
                if(s[i-1] > s[i] && s[i] < s[i+1]) ans++;
            }
        }

        return ans;
    }
};