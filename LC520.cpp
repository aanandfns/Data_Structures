class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(int i=0; i<word.size(); i++) {
            if(word[i] < 'a') cnt++;
        }
        if(cnt == word.size()) return true;

        for(int i=0; i<word.size(); i++) {
            if(i != 0 && word[i] < 'a') return false;
        }
        return true;
    }
};