class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        st.push(s[0]);

        for(int i=1; i<s.size(); i++) {
            if(!st.empty()){
                if(st.top() == '(' && s[i] == ')') {
                    st.pop();
                } else if(st.top() == '[' && s[i] == ']') {
                    st.pop();
                } else if(st.top() == '{' && s[i] == '}') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }

        if(st.empty()) return true;
        else return false;
    }
};

// Using Hash
class Solution {
public:
    bool isValid(string s) {
        map<char, char> hash = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(hash.find(s[i]) != hash.end()) st.push(s[i]);
            else if(!st.empty() && hash[st.top()] == s[i]) st.pop();
            else st.push(s[i]);
        }

        return st.empty();
    }
};