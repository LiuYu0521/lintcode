/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        while(head2)
        {
            ListNode* temp = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = head1->next->next;
            head2 = temp;
        }
    }
    ListNode* reverse(ListNode* now)
    {
        ListNode* pre = nullptr;
        while(now)
        {
            ListNode* temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }
        return pre;
    }
};


