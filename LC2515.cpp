class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int fs = 0;
        int ls = n - 1;

        if(find(words.begin(), words.end(), target) == words.end()) return -1;
        if(words[startIndex] == target) return 0;

        int i = (startIndex - 1 + n) % n;
        int cnt1 = 0;
        while(i != startIndex && words[i] != target) {
            cnt1++;
            i = (i - 1 + n) % n;
        }

        int cnt2 = 0;
        i = (startIndex + 1) % n;
        while(i != startIndex && words[i] != target) {
            cnt2++;
            i = (i + 1) % n;
        }

        return min(cnt1+1, cnt2+1);
    }
};