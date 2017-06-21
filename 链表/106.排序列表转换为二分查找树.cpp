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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head)
            return nullptr;
        if(!head->next)
            return new TreeNode(head->val);
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* last = slow;
        while(fast->next && fast->next->next)
        {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = nullptr;
        TreeNode* cur = new TreeNode(slow->val);
        if(head != slow)
            cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};


