class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        if (m < 0 || n < 0 || A == NULL || B == NULL) {
            return;
        }
        int i = m - 1;
        int j = n - 1;
        for (int k = m + n - 1; k >= 0; k--) {
            if (i >= 0 && j >=0 ) {
                if (A[i] > B[j]) {
                    A[k] = A[i--];
                } else {
                    A[k] = B[j--];
                }
            } else if (i >= 0) {
                return;
            } else if (j >= 0) {
                A[k] = B[j--];
            }
        }
        
    }
};
