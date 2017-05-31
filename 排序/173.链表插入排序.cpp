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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode* dummy = new ListNode(0);
        while(head != NULL)
        {
            ListNode* temp = dummy;
            ListNode* next = head->next;
            while(temp->next != NULL && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy->next;
    }
};
