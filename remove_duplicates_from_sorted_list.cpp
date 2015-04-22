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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode dummy_node(0);
        dummy_node.next = head;
        ListNode* pre_delete_node = &dummy_node;
        while(head != NULL && head->next != NULL) {
            if (head->val == head->next->val) {
                pre_delete_node->next = head->next;
                head = head->next;
                continue;
            }
            pre_delete_node = pre_delete_node->next;
            head = head->next;
            
        }
        return dummy_node.next;
    }
};
