/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    void reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
    }
    ListNode* findkth(ListNode* head, int k)
    {
        for(int i = 0; i < k; i++)
        {
            if(!head)
                return nullptr;
            head = head->next;
        }
        return head;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(m == n)
            return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* mth_pre = findkth(dummy, m - 1);
        ListNode* mth = mth_pre->next;
        ListNode* nth = findkth(dummy, n);
        ListNode* nth_next = nth->next;
        nth->next = nullptr;
        reverse(mth);
        mth_pre->next = nth;
        mth->next = nth_next;
        return dummy->next;
    }
};

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(m == n)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 0; i < m - 1; i++)
        {
            pre = pre->next;
        }
        ListNode* new_head = pre->next;
        ListNode* old_head = new_head->next;
        for(int i = 0; i < n - m; i++)
        {
            ListNode* temp = old_head->next;
            old_head->next = new_head;
            new_head = old_head;
            old_head = temp;
        }
        pre->next->next = old_head;
        pre->next = new_head;
        return dummy->next;
    }
};
