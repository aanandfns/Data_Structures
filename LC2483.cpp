class Solution {
public:
    int bestClosingTime(string cus) {
        int n = cus.size();
        vector<int> pre(n+1);

        int cnt = count(cus.begin(), cus.end(), 'N');
        pre.back() = cnt;
        int ans = n;

        for(int i=n-1; i>=0; i--) {
            if(cus[i] == 'Y') {
                pre[i] = pre[i+1] + 1;
            } else {
                pre[i] = pre[i+1] - 1;
            }

        }

        ans = min_element(pre.begin(), pre.end()) - pre.begin();
        return ans;
    }
};