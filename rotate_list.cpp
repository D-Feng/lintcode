/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        while (k > 0) {
            fast = fast->next;
            if (fast == NULL) {
                fast = head;
            }
            k--;
        }
        
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = NULL;
        fast->next = head;
        return temp;
    }
};
