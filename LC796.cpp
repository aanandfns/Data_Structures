// Brute Force ~ TC = O(n)
class Solution {
public:
    bool check(string s, string goal, int idx) {
       int j = 0;
        for(int i=idx; i<s.size(); i++) {
            if(s[i] != goal[j++]) return false;
        }

        for(int i=0; i<idx; i++) {
            if(s[i] != goal[j++]) return false;
        }
        
        return true;
    }

    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        bool ans;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == goal[0]) {
                ans = check(s, goal, i);
                if(ans == true) return true;
            }
        }
        return false;
    }
};

// OPTIMIZED ~ Can Also Use KMP Algorithm to here to find the substring
class Solution {
public:
    bool rotateString(string s, string goal) {
        string ds = s + s;
        if(s.size() != goal.size()) return false;

        // return ds.find(goal) != string::npos; ~ // .find() returns idx of starting of the substring
        return ds.find(goal) < ds.size();
    }
};