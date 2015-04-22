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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if (n <= 0) {
            return head;
        }
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        
        ListNode* pre_delete_node = &dummyNode;
        for (int i = 0; i < n; i++) {
            if (head == NULL) {
                return NULL;
            }
            head = head->next;
        }
        
        while(head != NULL) {
            head = head->next;
            pre_delete_node = pre_delete_node->next;
        }
        pre_delete_node->next = pre_delete_node->next->next;
        return dummyNode.next;
    }
};



