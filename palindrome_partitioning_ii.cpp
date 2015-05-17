class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        // f[i] the minimum cuts with i charachtes in s
        // f[0] = 0;
        // f[1] = 0
        // f[i] = min (f[i - 1] + 1, f[])
        int len = s.length();
        if (len == 0 || len == 1) {
            return 0;
        }
        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
        
        preProcess(isPalindrome, s);
        
        vector<int> f(len + 1, INT_MAX);
        f[0] = -1;
        f[1] = 0;
        
        for (int i = 2; i < len + 1; i++) {
            for (int j = 1; j <= i; j++) {
                if (isPalindrome[i - j][i - 1] && f[i - j] < INT_MAX) {
                    f[i] = min(f[i - j] + 1, f[i]);
                }
            }
        }
        
        return f[len];

    }
    
    void preProcess(vector<vector<bool>> &isPalindrome, const string &s) {
        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
        }
        
        for (int i = 0; i < s.length() - 1; i++) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
        }
        
        for (int i = 2; i < s.length(); i++) {
            for(int j = 0; j + i < s.length(); j++) {
                isPalindrome[j][j + i] = isPalindrome[j + 1][j + i - 1] && (s[j] == s[i + j]);
            }
        }
    }
};


