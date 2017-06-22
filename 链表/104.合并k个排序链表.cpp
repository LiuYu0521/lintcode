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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.size() == 0)
            return nullptr;
        int len = lists.size();
        while(len > 1)
        {
            int k = (len + 1) / 2;
            for(int i = 0; i < len / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            len = k;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if(l1)
            node->next = l1;
        if(l2)
            node->next = l2;
        return dummy->next;
    }
};


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
struct cmp{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
                q.push(lists[i]);
        }
        ListNode* head = nullptr;
        ListNode* pre = head;
        ListNode* temp = head;
        while(!q.empty())
        {
            temp = q.top();
            q.pop();
            if(!pre)
                head = temp;
            else
                pre->next = temp;
            pre = temp;
            if(temp->next)
                q.push(temp->next);
        }
        return head;
    }
};


