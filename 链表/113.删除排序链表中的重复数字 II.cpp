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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre->next)
        {
            ListNode* cur = pre->next;
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            if(pre->next != cur)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return dummy->next;
    }
};
