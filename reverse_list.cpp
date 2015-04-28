/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *pre = NULL;
        while (head != NULL) {
            //下述四个指针，出现顺序必须收尾相接。
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};

