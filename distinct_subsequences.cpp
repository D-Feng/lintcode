class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        // f[i][j] first i characters of S, with first j characters of T. the
        // count of distinct subsequences
        // f[i][0] = 1;
        // f[0][j] = 0
        // S[i - 1] == T[i - 1]
        // f[i][j] = f[i - 1][j - 1]
        // if (S[i -1] != T[i -1])
        // f[i][j] = f[i - 1][j]
        // S[i- 1]是否用于与T[i-1]match
        int len_s = S.size();
        int len_t = T.size();
        vector<vector<int>> f(len_s + 1, vector<int>(len_t + 1, 0));
        for (int i = 0; i < len_s + 1; i++) {
            f[i][0] = 1;
        }
        for (int j = 1; j < len_t + 1; j++) {
            f[0][j] = 0;
        }
        
        for (int i = 1; i < len_s + 1; i++) {
            for (int j = 1; j < min(len_t + 1, i + 1); j++) {
                f[i][j] = f[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    f[i][j] += f[i - 1][j - 1];
                }
            }
        }
        
        return f[len_s][len_t];
    }
};

