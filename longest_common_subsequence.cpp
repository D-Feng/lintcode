class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        // f[i][j] the length of LCS of first i elements of A and first j elements of B
        // f[0][j] = 0; f[i][j] = 0;
        // f[i][j] = if a[i - 1] != a[j - 1]
        //            = max (f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1] + 1
        // a[0] a[1] ... a[i]
        // b[0] b[1] ... b[j]
        
        int len_a = A.size();
        int len_b = B.size();
        if (len_a <= 0 || len_b <= 0) {
            return 0;
        }
        
        vector<vector<int>> f(len_a + 1, vector<int>(len_b + 1, 0));
        
        for (int i = 1; i < len_a + 1; i++) {
            for (int j = 1; j < len_b + 1; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }
        return f[len_a][len_b];
    }
};

