class Solution {
public:
    /**
     * @param stk an integer stack
     * @return void
     */
    void stackSorting(stack<int>& stk) {
        // Write your code here
        int len = stk.size();
        if (len <= 1) {
            return;
        }
        
        stack<int> temp;
        int min_num = INT_MAX;
        int former_min = INT_MAX;
        while (len > 0) {

            for (int i = 0; i < len; i++) {
                if (stk.top() < min_num) {
                    if (min_num != INT_MAX) {
                        temp.push(min_num);
                    }
                    min_num = stk.top();
                } else {
                    temp.push(stk.top());
                }
                stk.pop();
            }
            if (former_min != INT_MAX) {
                stk.push(former_min);
                former_min = INT_MAX;
                
            }
            stk.push(min_num);
            min_num = INT_MAX;
            len--;
            
            for (int i = 0; i < len; i++) {
                if (temp.top() < former_min) {
                    if (former_min != INT_MAX) {
                        stk.push(former_min);
                    }
                    former_min = temp.top();
                } else {
                    stk.push(temp.top());
                }
                temp.pop();
            }
            len--;
        }
        
        if (former_min != INT_MAX) {
            stk.push(former_min);
            former_min = INT_MAX;
        }
        
    }
};