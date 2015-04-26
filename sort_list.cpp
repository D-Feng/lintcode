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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* preMid = getMidPre(head);
        ListNode* right = sortList(preMid->next);
        preMid->next = NULL;
        ListNode* left = sortList(head);
        return mergeSortedList(left, right);
    }
    
    ListNode *mergeSortedList(ListNode *a, ListNode *b) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (a != NULL) {
            p->next = a;
        }
        if (b != NULL) {
            p->next = b;
        }
        return dummy.next;
    }
    
    ListNode *getMidPre(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        //主要是为了handle 2个node的情况，返回mid前一个node的原因是，
        //可以通过->next得到后半段的链表，同时通过->next = null截断前半部分的链表
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

