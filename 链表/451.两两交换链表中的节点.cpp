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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(!head || !head->next)
            return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur)
        {
            swap(pre->val, cur->val);
            pre = cur->next;
            if(!pre)
                return head;
            cur = cur->next->next;
        }
        return head;
    }
};

class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        dummy->next = head;
        while(pre->next && pre->next->next)
        {
            ListNode* temp = pre->next->next;
            pre->next->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            pre = temp->next;
        }
        return dummy->next;
    }
};
