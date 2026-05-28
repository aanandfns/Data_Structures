class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = 1;

        for(int k=0; k<9; k++) {
            set<char> s;
            set<char> x;
            for(int i=0; i<9; i++) {
                if(board[i][k] != '.') {
                    if(!s.count(board[i][k])) s.insert(board[i][k]);
                    else {
                        ans = 0;
                        break;
                    }
                } 

                if(board[k][i] != '.') {
                    if(!x.count(board[k][i])) x.insert(board[k][i]);
                    else {
                        ans = 0;
                        break;
                    }
                }
            }
            if(ans == 0) break;
        }

        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {

                set<char> s;
                for(int x=i; x<i+3; x++) {
                    for(int y=j; y<j+3; y++) {
                        if(board[x][y] != '.') {
                            if(!s.count(board[x][y])) s.insert(board[x][y]);
                            else {
                                ans = 0;
                                break;
                            }
                        }
                    }
                    if(ans == 0) break;
                }

                if(ans == 0) break;
            }
            if(ans == 0) break;
        }

        return ans;
    }
};