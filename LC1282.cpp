class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        vector<vector<int>> ans;
        map<int, vector<int>> hash;
        for(int i=0; i<gp.size(); i++) {
            hash[gp[i]].push_back(i);
        }

        for(auto it : hash) {
            vector<int> temp = it.second;
            if(temp.size() > it.first) {
                vector<int> tp;
                for(int i=0; i<temp.size(); i++) {
                    if(tp.size() < it.first) tp.push_back(temp[i]);
                    else {
                        ans.push_back(tp);
                        tp.clear();
                        tp.push_back(temp[i]);
                    }
                }
                if(!tp.empty()) ans.push_back(tp);
            } else {
                ans.push_back(temp);
            }
        }

        return ans;
    }
};