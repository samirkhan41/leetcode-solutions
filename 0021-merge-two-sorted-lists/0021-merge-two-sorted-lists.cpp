class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        // Jo list bach gayi, usko attach kar do
        if (list1 != nullptr) {
            temp->next = list1;
        }
        else {
            temp->next = list2;
        }

        return dummy->next;
    }
};