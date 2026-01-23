// SC : O(n) ~ TC : O(nm)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        vector<int> temp;
        for(int i=0; i<bank.size(); i++) {
            int cnt = 0;
            for(int j=0; j<bank[i].size(); j++) {
                if(bank[i][j] == '1') cnt++;
            }

            if(cnt!=0)temp.push_back(cnt);
        }

        if(!temp.empty()) {
            for(int i=0; i<temp.size()-1; i++) {
                ans += (temp[i] * temp[i+1]);
            }
        }

        return ans;
    }
};

// SC : O(1) ~ TC : O(nm)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        for(int i=0; i<bank.size(); i++) {
            int device = 0;
            for(int j=0; j<bank[i].size(); j++) {
                if(bank[i][j] == '1') device++;
            }

            if(device > 0) {
                ans += prev * device;
                prev = device;
            }
        }

        return ans;
    }
};