class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int len_a = A.size();
        int len_b = B.size();
        
        int len = len_a + len_b;
        if (len%2 == 0) {
            return (findKth(A, 0, B, 0, len / 2) + findKth(A, 0, B, 0, len / 2 + 1)) / 2.0;
        } else {
            return findKth(A, 0, B, 0, len / 2 + 1);
        }
    }
    
private:
    int findKth(const vector<int> &A, int start_A, const vector<int> &B,\
        int start_B, int k) {
            if (start_A >= A.size()) {
                return B[start_B + k - 1];
            }
            
            if (start_B >= B.size()) {
                return A[start_A + k - 1];
            }
            if (k == 1) {
                return A[start_A] < B[start_B] ? A[start_A] : B[start_B]; 
            }
            int key_a = start_A + k / 2 - 1< A.size() ? A[start_A + k / 2 - 1] : INT_MAX;
            int key_b = start_B + k / 2 - 1< B.size() ? B[start_B + k / 2 - 1] : INT_MAX;
            
            if (key_a > key_b) {
                
                return findKth(A, start_A, B, start_B + k / 2, k - k / 2);
            }
            
            return findKth(A, start_A + k / 2, B, start_B, k - k / 2);
            
        }
};

