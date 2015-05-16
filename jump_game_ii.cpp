class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int len = A.size();
        if (len == 0) {
            return 0;
        }
        vector<int> dp(len, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < INT_MAX && j + A[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                    //dp[j] must be less than dp[j + 1 ...]
                    //so break here.
                    break;
                }
            }
        }
        
        return dp[len - 1];
    }
};
