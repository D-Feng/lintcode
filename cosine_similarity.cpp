class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if (A.size() != B.size() || A.size() == 0) {
            return 2.0;
        }
        
        int len = A.size();
        int sum_ab = 0;
        int sum_a2 = 0;
        int sum_b2 = 0;
        for (int i = 0; i < len; i++) {
            
            sum_ab += A[i]*B[i];
            sum_a2 += A[i]*A[i];
            sum_b2 += B[i]*B[i];
        }
        
        if (sum_a2 == 0 || sum_b2 == 0) {
            return 2.0;
        }
        
        return double (sum_ab) / (std::sqrt(double(sum_a2)) * std::sqrt(double(sum_b2)));
    }
};

