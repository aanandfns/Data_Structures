class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* first = head;
        ListNode* sec = head;
        ListNode* mover = head;

        int n = 0;
        while(mover) {
            mover = mover->next;
            n++;
        }

        int val = n - k; 
        k--;
        while(k--) {
            first = first->next;
        }
        while(val--) {
            sec = sec->next;
        }
        swap(sec->val, first->val);
        return head;
    }
};