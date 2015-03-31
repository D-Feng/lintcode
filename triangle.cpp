class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        // f[i][j] is first i step minimus cost arrive at j
        // f[i][j] = min (f[i - 1][j], f[i-1][j-1] + A[i][j]
        
        int levels = triangle.size();
        
        vector<vector<int>> f(levels, vector<int>(levels, 0));
        
        f[0][0] = triangle[0][0];
        
        for (int i = 1; i < levels; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == i) {
                    f[i][j] = f[i - 1][j - 1];
                } else if (j == 0) {
                    f[i][j] = f[i - 1][j];
                } else {
                    f[i][j] = f[i - 1][j - 1] < f[i - 1][j] ? f[i - 1][j - 1] : f[i - 1][j];
                }
                f[i][j] += triangle[i][j];
            }
        }
        
        int cost = f[levels - 1][0];
        for (int i = 1; i < levels; i++) {
            if (f[levels - 1][i] < cost) {
                cost = f[levels - 1][i];
            }
        }
        return cost;
    }
};

