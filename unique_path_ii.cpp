class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
                // wirte your code here
        // f[i][j] count of unique ways to get to i j
        // f[1][i] = 1
        // f[j][1] = 1
        // f[i][j] = f[i - 1][j] + f[i][j - 1] 
        int m = obstacleGrid.size();
        if (m <= 0) 
            return 0;
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        
        int i = 1;
        while(i < m + 1 && obstacleGrid[i - 1][0] == 0) {
            f[i][1] = 1;
            i++;
        }
        int j = 1;
        while(j < n + 1 && obstacleGrid[0][j - 1] == 0) {
            f[1][j] = 1;
            j++;
        }
        
        for (int i = 2; i < m + 1; i++) {
            for (int j = 2; j < n + 1; j++) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    f[i][j] = 0;
                    continue;
                }
                if (obstacleGrid[i - 2][j - 1] != 1) {
                    f[i][j] += f[i - 1][j];
                }
                if (obstacleGrid[i - 1][j - 2] != 1) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m][n];
        
        
    }
};
