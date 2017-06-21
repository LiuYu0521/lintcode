/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        if(!root)
            return nullptr;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        DoublyListNode* head = nullptr;
        DoublyListNode* prev = nullptr;
        while(cur || !stack.empty())
        {
            while(cur)
            {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            DoublyListNode* node = new DoublyListNode(cur->val);
            if(head == nullptr)
            {
                head = node;
            }
            node->prev = prev;
            if(prev)
            {
                prev->next = node;
            }
            cur = cur->right;
            prev = node;
        }
        return head;
    }
};


