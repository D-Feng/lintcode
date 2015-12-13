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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        
        
        ListNode *l1r = reverse(l1);
        ListNode *l2r = reverse(l2);
        
        ListNode dummy(0);
        ListNode *head = &dummy;
        int carry = 0;
        while (l1r != NULL && l2r != NULL) {
            int sum_val = l1r->val + l2r->val + carry;
            ListNode *sum = new ListNode(sum_val % 10);
            head->next = sum;
            head = head->next;
            l1r = l1r->next;
            l2r = l2r->next;
            carry = (sum_val / 10);
        }
        
        ListNode *p = (l1r == NULL ? l2r : l1r);
        
        while(p != NULL) {
            int sum_val = p->val + carry;
            head->next = new ListNode(sum_val % 10);
            head = head->next;
            p = p->next;
            carry = (sum_val / 10);
        }
        
        while (carry != 0) {
            head->next = new ListNode(carry % 10);
            head = head->next;
            carry = carry / 10;
        }
        
        return reverse(dummy.next);
        
        
        
    }
    
    ListNode *reverse(ListNode *node) {
        
        ListNode dummy(0);
        ListNode* head = node;
        while (head != NULL) {
            
            ListNode* temp = dummy.next;
            dummy.next = head;
            head = head->next;
            dummy.next->next = temp;
        }
        
        return dummy.next;
    }
    
};