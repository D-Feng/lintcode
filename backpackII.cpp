class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        // f[i][j] first i elements, package size j, max value
        // f[i][j] = max (f[i - 1][j], f[i - 1][j - A[i - 1] ] + v[i - 1]] 
        // f[0][j] = 0
        // f[i][0] = 0
        
        if (m <= 0 || A.size() != V.size() || A.size() == 0)
            return 0;
        int len = A.size();
        vector<vector<int>> f(len + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= m; j++) {
                int temp = f[i - 1][j];
                if (j - A[i - 1] >= 0) {
                    temp = temp > f[i - 1][j - A[i - 1]] + V[i - 1] ? temp : f[i - 1][j - A[i - 1]] + V[i - 1];
                }
                f[i][j] = temp;
            }
        }
        return f[len][m];
    }
};


//Given n items with size A[i] and value V[i], and a backpack with size m. What's the maximum value can you put into the backpack?
//Note
//You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

//Example
//Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.