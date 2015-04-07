class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        // f[0] = 1
        // f[1] = 1;
        // f[2] = 2;
        // f[3] = 5;
        
        // f[n] = Sigma (f[n - i] * f[i], i = 1 ... n - 1 )
        
        // 1, 2, 3, 4, 5, 6 ,7
        if (n < 0) {
            return 0;
        }
        int m = n;
        if (n < 3) {
            m = 3;
        }
        
        vector<int> f(m + 1, 0);
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
};
