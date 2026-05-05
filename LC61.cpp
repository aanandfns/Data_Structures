// TC : O(n) and SC = O(n);
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        vector<int> temp;
        ListNode* mover = head;
        while(mover) {
            temp.push_back(mover->val);
            mover = mover->next;
        }

        int n = temp.size();
        
        int idx = 0;
        mover = head;
        k = k % n;
        while(mover) {
            mover->val = temp[(idx+n-k)%n];
            mover = mover->next;
            idx++;
        }

        return head;
    }
};