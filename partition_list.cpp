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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode dummyLess(0);
        ListNode dummyGreater(0);
        
        ListNode *headLess = &dummyLess;
        ListNode *headGreater = &dummyGreater;
        
        while (head != NULL) {
            if (head->val < x) {
                headLess->next = head;
                headLess = headLess->next;
            } else {
                headGreater->next = head;
                headGreater = headGreater->next;
            }
            head = head->next;
        }
        headGreater->next = NULL;
        headLess->next = dummyGreater.next;
        return dummyLess.next;
        
        
    }
};
