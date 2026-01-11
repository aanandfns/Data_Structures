// generating all possible strings then picking the answers from them 
// TC = O(n * 2^n)
class Solution {
public:
    void helper(int n, string temp, vector<string>& ans) {
        if((int)temp.size() == n) {
            for(int i=1; i<temp.size(); i++) {
                if(temp[i-1] == '0' && temp[i] == '0') return;
            }
            ans.push_back(temp);
            return;
        }

        temp += '0';
        helper(n, temp, ans);
        temp.pop_back();
        temp += '1';
        helper(n, temp, ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n, "", ans);
        return ans;
        
    }
};

// with some checks
// TC = O( 2^n )
class Solution {
public:
    void helper(int n, int i, string temp, vector<string>& ans) {
        if(i == n || temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        bool flag = false;
        if(temp.empty()) {temp += '0'; flag = true;}
        else if(temp.back() == '1') {temp += '0'; flag = true;}

        if(flag) {
            helper(n, i+1, temp, ans);
            temp.pop_back();
        }

        temp += '1';
        helper(n, i+1, temp, ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n, 0, "", ans);
        return ans;
        
    }
};

// much simplified
// TC = O( 2^n )
class Solution {
public:
    void helper(int n, string temp, vector<string>& ans) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        temp += '1';
        helper(n, temp, ans);

        temp.pop_back();
        if(temp.back() == '1') {
            temp += '0';
            helper(n, temp, ans);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string a = "0", b = "1";
        helper(n, a, ans);
        helper(n, b, ans);
        return ans;
        
    }
};

// or int the above code we can swap the function calls 
// TC = O( 2^n )
class Solution {
public:
    void helper(int n, string temp, vector<string>& ans) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        if(temp.back() == '1') {
            temp += '0';
            helper(n, temp, ans);
            temp.pop_back();
        }

        temp += '1';
        helper(n, temp, ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string a = "0", b = "1";
        helper(n, a, ans);
        helper(n, b, ans);
        return ans;
        
    }
};