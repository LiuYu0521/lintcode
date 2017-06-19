/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        dummy->next = head;
        while(pre->next)
        {
            if(pre->next->val == val)
            {
                ListNode* temp = pre->next;
                pre->next = temp->next;
                temp->next = nullptr;
                delete(temp);
            }
            else
                pre = pre->next;
        }
        return dummy->next;
    }
};
