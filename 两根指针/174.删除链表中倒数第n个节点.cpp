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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head)
        {
            head = head->next;
            delete(slow);
        }
        else
        {
            ListNode* temp = slow->next;
            slow->next = temp->next;
            delete(temp);
        }
        return head;
    }
};


