class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(apple.begin(), apple.end());
        sort(capacity.begin(), capacity.end());

        int sum = 0;
        for(int i=0; i<n; i++) sum += apple[i];

        int ans = 0;
        for(int i=m-1; i>=0; i--) {
            sum -= capacity[i];
            ans++;
            if(sum <= 0) break;
        }

        return ans;
    }
};