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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (!isFinished(lists)) {
            ListNode *minimum = NULL;
            int minInd = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL ) {
                    if (minimum == NULL) {
                        minimum = lists[i];
                        minInd = i;
                    } else {
                        if (lists[i]->val < minimum->val) {
                            minimum = lists[i];
                            minInd = i;
                        }
                    }
                }
            }
            
            pre->next = minimum;
            pre = pre->next;
            lists[minInd] = lists[minInd]->next;
            
        }
        return dummy.next;
    }
    
    bool isFinished(vector<ListNode *> &lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                return false;
            }
        }
        return true;
    }
};



