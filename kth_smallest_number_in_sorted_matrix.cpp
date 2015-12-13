class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    class Element {
        public:
            int val, row, col;
            Element(int a, int b, int c) {
                this->val = a;
                this->row = b;
                this->col = c;
            }
    };
    
    struct Comparator {
        bool operator() (const Element& a, const Element& b) {
            return a.val > b.val;
        }
        
    };
     
    
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int row = matrix.size();
        if (row == 0) return -1;
        int col = matrix[0].size();
        if (col == 0) return -1;
        
        priority_queue<Element, vector<Element>, Comparator> min_heap;
        
        
        for (int i = 0; i < row; i++) {
            min_heap.push(Element(matrix[i][0], i, 0));
        }
        
        while (k > 1) {
            const Element& it = min_heap.top();
            int r = it.row;
            int c = it.col;
            min_heap.pop();
            if (c + 1 < col) {
                min_heap.push(Element(matrix[r][c + 1], r, c + 1));
            }
            k--;
        }
        
        return min_heap.top().val;
    }
};