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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode* p1 = &dummy1;
        ListNode* p2 = &dummy2;
        while (head != NULL && head->next != NULL) {
            p1->next = head;
            p2->next = head->next;
            
            head = head->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1->next = head;
        p2->next = NULL;
        
        ListNode dummy(0);
        ListNode *p = &dummy;
        p1 = dummy1.next;
        p2 = dummy2.next;
        while (p2 != NULL) {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        
        p->next = p1;
        return dummy.next;
        
    }
};
