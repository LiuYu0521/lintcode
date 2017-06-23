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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy;
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        while(cur->next)
        {
            if(cur->next->val == v1 || cur->next->val == v2)
            {
                if(!p1)
                {
                    p1 = cur->next;
                    pre = cur;
                }
                else
                {
                    ListNode* t = cur->next->next;
                    p2 = cur->next;
                    pre->next = p2;
                    if(cur == p1)
                    {
                        p2->next = p1;
                        p1->next = t;
                    }
                    else
                    {
                        p2->next = p1->next;
                        cur->next = p1;
                        p1->next = t;
                    }
                    return dummy->next;
                }
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
