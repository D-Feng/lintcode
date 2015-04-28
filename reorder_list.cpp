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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        
        ListNode *preMid = findPreMid(head);
        ListNode *right_part = preMid->next;
        preMid->next = NULL;
        ListNode *left_part = head;
        right_part = reverse(right_part);
        
        while (left_part != NULL && right_part != NULL) {
            ListNode* temp = left_part->next;
            left_part->next = right_part;
            ListNode* temp2 = right_part->next;
            right_part->next = temp;
            left_part = temp;
            right_part = temp2;

        }
    }
    
    ListNode* reverse(ListNode *head) {
        ListNode dummy(0);
        while (head != NULL) {
            ListNode* temp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = temp;
        }
        return dummy.next;
        
        
    }
    
    ListNode* findPreMid(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
};



