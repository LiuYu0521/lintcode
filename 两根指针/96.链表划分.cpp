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
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* small_head = new ListNode(0);
        ListNode* small_tail = small_head;
        ListNode* big_head = new ListNode(0);
        ListNode* big_tail = big_head;
        while(head != nullptr)
        {
            if(head->val < x)
            {
                small_tail->next = head;
                small_tail = small_tail->next;
            }
            else
            {
                big_tail->next = head;
                big_tail = big_tail->next;
            }
            head = head->next;
        }
        small_tail->next = big_head->next;
        delete(big_head);
        big_tail->next = nullptr;
        ListNode* temp = small_head;
        small_head = small_head->next;
        delete(temp);
        return small_head;
    }
};


