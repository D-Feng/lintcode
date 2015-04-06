class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        // f[i][j] lenght of first elements of A and first j elements of B
        // with i and j as its last charactor of substring 
        
        // f[0][j] = 0; f[i][0] = 0;
        // f[i][j] = 0 if A[i - 1] != B[i - 1]
        
        int len_a = A.size();
        int len_b = B.size();
        if (len_a <= 0 || len_b <= 0) {
            return 0;
        }
        
        vector<vector<int>> f(len_a + 1, vector<int> (len_b + 1, 0));
        
        int lcs_length = 0;
        for (int i = 1; i < len_a + 1; i++) {
            for (int j = 1; j < len_b + 1; j++) {
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = 0;
                }
                if (f[i][j] > lcs_length) {
                    lcs_length = f[i][j];
                }
            }
        }
        return lcs_length;
    }
};

