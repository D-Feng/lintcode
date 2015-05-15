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
        if (head == NULL) {
            return NULL;
        }
        
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }
        
        ListNode* pre_mid = findMid(head);
        ListNode* mid = pre_mid->next;
        TreeNode* root = new TreeNode(mid->val);
        pre_mid->next = NULL;
        
        root->left = sortedListToBST(head);

        root->right = sortedListToBST(mid->next);
        
        return root;
        
    }
    
    ListNode* findMid(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
};



