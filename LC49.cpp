// Brute Force ~ Not Accepted ~ TC : O(n^2 * klogk)
// if there is no time limit oyu can use this for the brute force apprach
class Solution {
public:
    bool checkAnagram(string a, string b) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a == b;
        }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        vector<bool> valid(n, true);

        for(int i=0; i<n; i++) {
            if(valid[i] == false) continue;
            
            vector<string> temp;
            temp.push_back(strs[i]);
            valid[i] = false;
            for(int j=i+1; j<n; j++) {
                if(valid[j] && checkAnagram(strs[j], temp.back())) {
                    temp.push_back(strs[j]);
                    valid[j] = false;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// Optimal ~ TC : O(n * klogk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string, vector<string>> hash;

        for(string &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            hash[key].push_back(s);
        }

        for(auto it : hash) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

//Can also solve by ASCII values
// RESOLVE