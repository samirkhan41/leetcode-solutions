
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap
        priority_queue<ListNode*, vector<ListNode*>,
                       decltype([](ListNode* a, ListNode* b) {
                           return a->val > b->val;
                       })> pq;

        // Push first node of every non-empty list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            // Add next node from the same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
