// basic solution
class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        int n = com.size();

        set<pair<int, int>> s;
        for(int i=0; i<obs.size(); i++) s.insert({obs[i][0], obs[i][1]});

        int x = 0, y = 0;
        int ans = INT_MIN;
        char dir = 'N';
        for(int i=0; i<n; i++) {

            if(com[i] == -1 || com[i] == -2) {
                if(dir == 'N') {
                    if(com[i] == -1) dir = 'W';
                    else dir = 'E';
                } else if(dir == 'W') {
                    if(com[i] == -1) dir = 'S';
                    else dir = 'N';
                } else if(dir == 'S') {
                    if(com[i] == -1) dir = 'E';
                    else dir = 'W';
                } else {
                    if(com[i] == -1) dir = 'N';
                    else dir = 'S';
                }

            } else {
                int steps = com[i];

                if(dir == 'N') {
                    for(int j=1; j<=steps; j++) {
                        if(s.find({x, y+1}) == s.end()) y++;
                        else break;
                    }

                } else if(dir == 'W') {
                    for(int j=1; j<=steps; j++) {
                        if(s.find({x+1, y}) == s.end()) x++;
                        else break;
                    }

                } else if(dir == 'S') {
                    for(int j=1; j<=steps; j++) {
                        if(s.find({x, y-1}) == s.end()) y--;
                        else break;
                    }

                } else {
                    for(int j=1; j<=steps; j++) {
                        if(s.find({x-1, y}) == s.end()) x--;
                        else break;
                    }

                }
                cout << x << " " << y << endl;
                ans = max(ans, x*x + y*y);
            }
        }

        return ans;
    }
};