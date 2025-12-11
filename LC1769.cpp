// Brute Force ~ TC : O(n^2)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n = boxes.size();

        for(int i=0; i<n; i++) {
            int val = 0;
            for(int j=0; j<n; j++) {
                if(boxes[j] == '1') {
                    val += abs(j-i);
                }
            }
            ans.push_back(val);
        }

        return ans;
    }
};

// Optimized but SC : not good, TC : O(n)
class Solution {
public:
    vector<int> minOperations(string ss) {
        int n = ss.size();

        int p = 0;
        int s = 0;
        int cnt = 0;

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            prefix[i] = p;
            if(ss[i] == '1') cnt++;
            p += cnt;
        }

        cnt = 0;
        for(int i=n-1; i>=0; i--) {
            suffix[i] = s;
            if(ss[i] == '1') cnt++;
            s += cnt;
        }

        for(int i=0; i<n; i++) {
            ans[i] = prefix[i] + suffix[i];
        }

        return ans;
    }
};

// Most optimized in terms of both TC : O(n) ans SC : O(n)
class Solution {
public:
    vector<int> minOperations(string ss) {
        int n = ss.size();

        int prefix = 0;
        int cnt = 0;
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            ans[i] = prefix;
            if(ss[i] == '1') cnt++;
            prefix += cnt;
        }

        cnt = 0;
        prefix = 0; // treat this same variable as suffix sum
        for(int i=n-1; i>=0; i--) {
            ans[i] = prefix + ans[i];
            if(ss[i] == '1') cnt++;
            prefix += cnt;
        }

        return ans;
    }
};