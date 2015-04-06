class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        //f[i][j][k] first i elements and j elements' were choosen, 
        //sum k's solution count
        
        //f[i][j][k] = f[i - 1][j][k] + f[i - 1][j - 1][k - A[i - 1]]
        
        int len = A.size();
        vector<vector<vector<int>>> f(len + 1, vector<vector<int>>(k + 1, vector<int> (target + 1, 0)) );
        
        //f[i][j][0] = 1; XXXXXXXXXXXXXXX this is where i am bugged.
        // Actually f[i][0][0] = 1....
        
        //thought: 0 can be ignore.
        //f[0][j][k] = 0;
        //f[i][0][k] = 0;
        
        for (int i = 0; i < len + 1; i++) {
                f[i][0][0] = 1;
        }
        
        for (int i = 1; i < len + 1; i++) {
            for (int j = 1; j < k + 1 && j < i + 1; j++) {
                for (int tar = 1; tar < target + 1; tar++) {
                    f[i][j][tar] = f[i - 1][j][tar];
                    if (tar >= A[i - 1]) {
                        f[i][j][tar] += f[i - 1][j - 1][tar - A[i - 1]];
                    }
                }
            }
        }
        return f[len][k][target];
    }
};
