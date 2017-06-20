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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if(!head)
            return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++)
        {
            if(fast)
                fast = fast->next;
            else
                return nullptr;
        }
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};


