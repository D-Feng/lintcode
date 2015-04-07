class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        // f[i][j] 到达 i j 的mini sum
        // f[i][j] = min (f[i - 1][j], f[i][j - 1] + grid[i][j] 
        
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        
        vector<vector<int>> f(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int temp = 0;
                
                if (i - 1 >= 0 && j - 1 >= 0) {
                    temp = min(f[i- 1][j], f[i][j - 1]);
                } else if (i - 1 >= 0) {
                    temp = f[i - 1][j];
                } else if (j - 1 >= 0) {
                    temp = f[i][j - 1];
                }

                f[i][j] = temp + grid[i][j];
            }
        }
        
        return f[m - 1][n- 1];
    }
};

