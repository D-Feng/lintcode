class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
     // the space complex can be optimized.
     //
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty() || m <= 0)
            return -1;
        vector<vector<bool>> f(A.size() + 1, vector<bool> (m + 1, false));
        //f[i][j] first i elements and backpack size j
        
        for (int i = 0; i < A.size() + 1; i++) {
            f[i][0] = true;
        }
        
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= m; j++) {
                bool temp = f[i - 1][j];
                if (j - A[i - 1] >= 0)
                    temp = temp || f[i-1][j - A[i - 1]];
                f[i][j] = temp;
            }
        }
        
        for (int i = m; m >=0; i--) {
            if (f[A.size()][i])
                return i;
        }
        return -1;
    }
};
