class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        
        vector<int> result(A.size() + B.size(), 0);
        int ind_a = A.size() - 1;
        int ind_b = B.size() - 1;
        for (int i = A.size() + B.size() - 1; i >= 0; i--) {
            if (ind_a >=0 && ind_b >=0) {
                if (A[ind_a] > B[ind_b]) {
                    result[i] = A[ind_a--];
                } else {
                    result[i] = B[ind_b--];
                }
            } else if(ind_a >= 0) {
                result[i] = A[ind_a--];
            } else {
                result[i] = B[ind_b--];
            }
        }
        return result;
    }
};
