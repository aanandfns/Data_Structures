class SubrectangleQueries {
public:
    vector<vector<int>> r;
    int rows = 0;
    int cols = 0;
    SubrectangleQueries(vector<vector<int>>& r) {
        rows = r.size();
        cols = r[0].size();
        this->r = r;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1; i<=row2; i++) {
            for(int j=col1; j<=col2; j++) {
                r[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return r[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */