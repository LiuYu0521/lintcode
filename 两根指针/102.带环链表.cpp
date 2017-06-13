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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(true)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == nullptr || fast->next == nullptr)
                return false;
            else if(fast == slow)
                return true;
        }
    }
};


