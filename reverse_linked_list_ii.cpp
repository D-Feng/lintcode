/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head == NULL || m >= n) {
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        for (int i = 1; i < m; i++) {
            if (head == NULL) {
                return NULL;//m > length of list
            }
            head = head->next;
        }
        
        ListNode *pre_m_node = head;
        ListNode *m_node = head->next;
        ListNode *n_node = m_node;
        ListNode *post_n_node = n_node->next;
        
        for (int i = m; i < n; i++) {
            if (post_n_node == NULL) {
                return NULL;
            }
            ListNode *temp = post_n_node->next;
            post_n_node->next = n_node;
            n_node = post_n_node;
            post_n_node = temp;
        }
        m_node->next = post_n_node;
        pre_m_node->next = n_node;
        
        return dummy.next;
        
    }
};

