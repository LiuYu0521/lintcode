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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head || !head->next)
            return head;
        ListNode* node = head;
        while(node->next)
        {
            if(node->val == node->next->val)
            {
                node->next = node->next->next;
            }
            else
            {
                node = node->next;
            }
        }
        return head;
    }
};
