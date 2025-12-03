class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i=0; i<lists.size(); i++) {
            ListNode* mover = lists[i];
            while(mover) {
                arr.push_back(mover->val);
                mover = mover->next;
            }
        }

        sort(arr.begin(), arr.end());
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        for(int i=0; i<arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        temp->next = nullptr;
        return dummynode->next;
    }
};