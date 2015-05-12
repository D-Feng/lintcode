/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        
        unordered_map<RandomListNode *, RandomListNode *> hashTable;
        RandomListNode *temp = head;
        while (temp != NULL) {
            RandomListNode *copy = new RandomListNode(temp->label);
            hashTable.insert({temp, copy});
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL)
                hashTable[temp]->random = hashTable[temp->random];
            if (temp->next != NULL)
                hashTable[temp]->next = hashTable[temp->next];
            temp = temp->next;
        }
        
        return hashTable[head];
        
    }
};
