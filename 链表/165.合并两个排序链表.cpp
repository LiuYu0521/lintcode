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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if(l1)
        {
            temp->next = l1;
        }
        if(l2)
        {
            temp->next = l2;
        }
        return dummy->next;
    }
};
