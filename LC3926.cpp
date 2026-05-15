class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& q) {
        string temp = "";
        for(int i=0; i<chunks.size(); i++) temp += chunks[i];

        string s = "";
        int n = temp.size();
        for(int i=0; i<n; i++) {
            if('a' <= temp[i] && temp[i] <= 'z') s += temp[i];

            if(temp[i] == ' ') {
                if(!s.empty() && 'a' <= s.back() && s.back() <= 'z') s += temp[i];
                else continue;
            }

            if(temp[i] == '-') {
                if(0 < i && i < n && ('a' <= temp[i-1] && temp[i-1] <= 'z') && ('a' <= temp[i+1] && temp[i+1] <= 'z')) 
                    s += temp[i];
                else s += " ";
            }
        }
        n = s.size();
        temp = "";
        map<string, int> st;
        for(int i=0; i<n; i++) {
            if(s[i] != ' ') temp += s[i];
            else {
                if(temp.size() > 0) st[temp]++;
                temp = "";
            }
        }
        if(temp.size() > 0) st[temp]++;

        vector<int> ans;
        for(int i=0; i<q.size(); i++) {
             ans.push_back(st[q[i]]);   
        }

        return ans;
    }
};