// Brute force using extra space ~ SC : O(n ~ almost)
class Solution {
public:
    string reverseWords(string s) {
        vector<string> ds;
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                if(!temp.empty()) ds.push_back(temp);
                temp = "";
            }
            else temp += s[i];
        }
        if(!temp.empty()) ds.push_back(temp);

        string ans ="";
        for(int i=ds.size()-1; i>=0; i--) {
            ans += ds[i];
            if(i != 0) ans += ' ';
        }

        return ans;
    }
};

