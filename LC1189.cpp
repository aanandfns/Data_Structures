class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> hash(26, 0);

        for(int i=0; i<n; i++) hash[text[i] - 'a']++;

        int ans = 1e5;
        ans = min(ans, hash[1]);
        ans = min(ans, hash[0]);
        ans = min(ans, hash['l' - 'a'] / 2);
        ans = min(ans, hash['o' - 'a'] / 2);
        ans = min(ans, hash['n' - 'a']);

        return ans;
    }
};