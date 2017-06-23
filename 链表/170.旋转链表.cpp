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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(!head)
            return nullptr;
        int count = 1;
        ListNode* cur = head;
        while(cur->next)
        {
            cur = cur->next;
            count++;
        }
        cur->next = head;
        int m = count - k % count;
        for(int i = 0; i < m; i++)
        {
            cur = cur->next;
        }
        ListNode* new_head = cur->next;
        cur->next = nullptr;
        return new_head;
    }
};
