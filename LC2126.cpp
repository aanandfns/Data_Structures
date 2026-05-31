class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        int n = ast.size();

        bool ans = 1;
        sort(ast.begin(), ast.end());
        int mx = *max_element(ast.begin(), ast.end());

        for(int i=0; i<n; i++) {
            if(mass >= mx) break;
            
            if(ast[i] <= mass) {
                mass += ast[i];
            } else {
                ans = 0;
                break;
            }
        }

        return ans;
    }
};