class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int len_s1 = s1.size();
        int len_s2 = s2.size();
        if (s3.size() != len_s1 + len_s2)
            return false;
        vector<vector<bool>> f(len_s1 + 1, vector<bool>(len_s2, 0));
        f[0][0] = true;
        
        for (int i = 1; i < len_s1 + 1; i++) {
            f[i][0] = f[i - 1][0] & (s1[i - 1] == s3[i - 1]);
        }
        
        for (int j = 1; j < len_s2 + 1; j++) {
            f[0][j] = f[0][j - 1] & (s2[j - 1] == s3[j - 1]);
        }
        //first i characters of s1, first j characters of s2, first i + j characters of s3
        // s1[i - 1] != s3[i + j - 1] && s2[j - 1] != s3[i + j - 1]
        // f[i][j] = false
        // s1[i - 1] == s3[i + j - 1]
        // f[i][j] = f[i - 1][j]
        // f[i][j] = f[i][j - 1]
        
        for (int i = 1; i < len_s1 + 1; i++) {
            for (int j = 1; j < len_s2 + 1; j++) {
                f[i][j] = false;
                if (s1[i - 1] == s3[i + j - 1]) {
                    f[i][j] = f[i][j] | f[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    f[i][j] = f[i][j] | f[i][j - 1];
                }
            }
        }
        
        return f[len_s1][len_s2];
    }
};
