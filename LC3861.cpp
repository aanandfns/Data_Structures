class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int val = INT_MAX;
        int idx = -1;
        int n = capacity.size();
        for(int i=0; i<n; i++) {
            if(capacity[i] >= itemSize && capacity[i] < val) {
                val = capacity[i];
                idx = i;
            }
        }

        return idx;
    }
};