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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        stack<int> s1, s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* res = new ListNode(0);
        while(!s1.empty() || !s2.empty())
        {
            if(!s1.empty())
            {
                sum = sum + s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum = sum + s2.top();
                s2.pop();
            }
            res->val = sum % 10;
            ListNode* head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum = sum / 10;
        }
        return res->val == 0 ? res->next : res;
    }
};
