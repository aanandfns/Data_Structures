// Using hash -> TC : O(N * logN) -> SC : O(score.size())

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        
        vector<pair<int, int>> hash;
        for(int i=0; i<score.size(); i++) {
            hash.push_back({score[i][k], i});
        }

        sort(hash.rbegin(), hash.rend());
        for(int i=0; i<score.size(); i++) {
            ans.push_back(score[ hash[i].second ]);
        }

        return ans;
    }
};

// Using Bubble Sort -> TC : O(n^2)

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(score[j][k] < score[j+1][k]) {
                    swap(score[j], score[j+1]);
                }
            }
        }

        return score;
    }
};