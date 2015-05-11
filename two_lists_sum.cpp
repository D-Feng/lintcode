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
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int increase = 0;
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (l1 != NULL || l2 != NULL || increase != 0) {
            int num_sum = 0;
            if (l1 != NULL) {
                num_sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                num_sum += l2->val;
                l2 = l2->next;
            }
            num_sum += increase;
            increase = num_sum / 10;
            
            ListNode* sum = new ListNode(num_sum % 10);
            head->next = sum;
            head = head->next;
        }
        
        return dummy.next;
        
    }
};
