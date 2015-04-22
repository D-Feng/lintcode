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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode dummy_node(0);
        dummy_node.next = head;
        head = &dummy_node;
        while(head->next != NULL && head->next->next != NULL) {
            if (head->next->val == head->next->next->val) {
                ListNode* first_diff_node = head->next->next->next;
                while(first_diff_node != NULL && first_diff_node->val == head->next->val) {
                    first_diff_node = first_diff_node->next;
                }
                head->next = first_diff_node;
            } else {
                head = head->next;
            }
        }
        return dummy_node.next;
        
    }
};
