class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
     
    // f[i] A[0...i - 1] can reach the last one
  
    bool canJump(vector<int> A) {
        // write you code here
        int len = A.size();
        if (len == 0) {
            return true;
        }
        
        if (A[0] == 0) {
            return false;
        }
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        dp[1] = true;
        
        for (int i = 2; i < len + 1; i++) {
            for(int j = 1; j < i; j++) {
                if (dp[j] && A[j - 1] + j >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[len];
    }
    
    
};

