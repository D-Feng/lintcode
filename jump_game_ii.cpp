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



    int jump_ii(vector<int> A) {
        // wirte your code here
        int farest = 0;
        int current = 0;
        int jump = 0;
        
        for (int i = 0; i < A.size() - 1; i++) {
            
            if (farest < i) return -1;
            farest = A[i] + i > farest ? A[i] + i : farest;
            
            if (current == i) {
                ++jump;
                current = farest;
            }
            
            if (farest >= A.size() -1) {
                if (current < farest) {
                    jump++;
                }
                return jump;
            }
        }
        
        if (farest >= A.size() - 1)
            return jump;
            
        return -1;
    }
};
