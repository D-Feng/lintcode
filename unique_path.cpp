class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        // f[i][j] count of unique ways to get to i j
        // f[1][i] = 1
        // f[j][1] = 1
        // f[i][j] = f[i - 1][j] + f[i][j - 1] 
        
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i < m + 1; i++) {
            f[i][1] = 1;
        }
        for (int j = 1; j < n + 1; j++) {
            f[1][j] = 1;
        }
        
        for (int i = 2; i < m + 1; i++) {
            for (int j = 2; j < n + 1; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m][n];
    }
};

