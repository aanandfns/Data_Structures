class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size();

        int x = 0, y = 0, cnt = 0;
        for(int i=0; i<n; i++) {
            if(moves[i] == 'U') y++;
            else if(moves[i] == 'D') y--;
            else if(moves[i] == 'L') x--;
            else if(moves[i] == 'R') x++;
            else cnt++;
        }

        return abs(x) + abs(y) + cnt;
    }
};