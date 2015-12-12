class Solution {
public:
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
     
    class Element {
        public:
            int val;
            int row;
            int col;
            Element(int a, int b, int c) {
                this->val = a;
                this->row = b;
                this->col = c;
            }
    };
    
    
    struct comparator {
        bool operator() (const Element &a, const Element &b) {
            return a.val > b.val;
        }
    };
    
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        // Write your code here
    
        int k = arrays.size();
        vector<int> result;
        
        priority_queue<Element, vector<Element>, comparator> min_heap;
        
        vector<int> len;
        
        for (int i = 0; i < k; i++) {
            len.push_back(arrays[i].size());
            if (arrays[i].size() > 0) {
                min_heap.push(Element(arrays[i][0], i, 0));
            }
        }
        
        while (!min_heap.empty()) {
            
            result.push_back(min_heap.top().val);
            int row = min_heap.top().row;
            int col = min_heap.top().col;
            min_heap.pop();
            
            if(col + 1 < len[row]) {
                min_heap.push(Element(arrays[row][col + 1], row, col + 1));
            }
        }
        
        return result;
    }
};