/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(!head)
            return nullptr;
        RandomListNode* res = new RandomListNode(head->label);
        RandomListNode* node = res;
        RandomListNode* cur = head->next;
        map<RandomListNode*, RandomListNode*> m;
        m[head] = res;
        while(cur)
        {
            RandomListNode* temp = new RandomListNode(cur->label);
            node->next = temp;
            m[cur] = temp;
            cur = cur->next;
            node = node->next;
        }
        node = res;
        cur = head;
        while(cur)
        {
            node->random = m[cur->random];
            cur = cur->next;
            node = node->next;
        }
        return res;
    }
};


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(!head)
            return nullptr;
        RandomListNode* cur = head;
        while(cur)
        {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while(cur)
        {
            if(cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        RandomListNode* res = head->next;
        while(cur)
        {
            RandomListNode* temp = cur->next;
            cur->next = temp->next;
            if(temp->next)
            {
                temp->next = temp->next->next;
            }
            cur = cur->next;
        }
        return res;
    }
};
