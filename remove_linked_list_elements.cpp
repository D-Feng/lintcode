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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        
        ListNode dummy(0);
        ListNode *p = &dummy;
        
        while(head != NULL) {
            if (head->val != val) {
                p->next = head;
                p = p->next;
            }
            
            head = head->next;
        }
        //dont forget the last null pointer!!!
        p->next = NULL;
        
        return dummy.next;
        
    }
};
