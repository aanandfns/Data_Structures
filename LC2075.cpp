class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if(s.empty()) return "";

        int n = s.size();
        int cols = n / rows;

        string ans = "";
        for(int i=0; i<cols; i++) {
            
            ans += s[i];
            for(int j=i+cols+1; j<n;) {
                if(j < n) ans += s[j];
                j += cols+1;
            }
        }

        while(ans.back() == ' ') ans.pop_back();

        return ans;

    }
};