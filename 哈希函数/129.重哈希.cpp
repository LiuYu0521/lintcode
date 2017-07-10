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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    void addListNode(ListNode* node, int number)
    {
        if(node->next)
            addListNode(node->next, number);
        else
            node->next = new ListNode(number);
    }
    void addNode(vector<ListNode*> &res, int number)
    {
        int p = (number + res.size()) % res.size();
        if(!res[p])
            res[p] = new ListNode(number);
        else
            addListNode(res[p], number);
    }
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        vector<ListNode*> res;
        for(int i = 0; i < hashTable.size() * 2; i++)
        {
            res.push_back(nullptr);
        }
        for(int i = 0; i < hashTable.size(); i++)
        {
            ListNode* p = hashTable[i];
            while(p)
            {
                addNode(res, p->val);
                p = p->next;
            }
        }
        return res;
    }
};
