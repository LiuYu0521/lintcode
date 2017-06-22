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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if(!head || !head->next)
            return true;
        ListNode* mid = findmid(head);
        mid->next = reverse(mid->next);
        mid = mid->next;
        while(head && mid)
        {
            if(head->val != mid->val)
                return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode* findmid(ListNode* now)
    {
        ListNode* slow = now;
        ListNode* fast = now;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
