/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int k) {
        while(head != nullptr && head->val == k) {
            head = head->next;
        }

        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp != nullptr) {
            if(temp->val == k) {
                prev->next = temp->next;
                //memory leak
                temp = temp->next;
            } else {
                prev = temp;
                if(temp) temp = temp->next;
            }
        }
        return head;
    }
};