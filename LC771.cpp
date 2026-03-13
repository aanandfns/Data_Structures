class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> st(jewels.begin(), jewels.end());

        int ans = 0;
        for(int i=0; i<stones.size(); i++) {
            if(st.find(stones[i]) != st.end()) ans++;
        }

        return ans;
    }
};