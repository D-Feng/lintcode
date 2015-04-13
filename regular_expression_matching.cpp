class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isSame(char &a, char &b) {
        if (a == '.' || b == '.') 
            return true;
        return a == b;
    }
    bool isMatch(const char *s1, const char *p1) {
        // write your code here
        string s(s1);
        string p(p1);
        
        int len_s = s.size();
        int len_p = p.size();
        
        vector<vector<bool>> f(len_s + 1, vector<bool>(len_p, false));
        f[0][0] = true;
        for (int i = 1; i < len_s + 1; i++) {
            f[i][0] = false;
        }
        
        for (int i =  0; i < len_s + 1; i++) {
            for (int j = 1; j < len_p + 1; j++) {
                if (i - 1 >=0  && isSame(s[i - 1], p[j - 1])) {
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (j - 2 >= 0 && f[i][j - 2]) {
                        f[i][j] = true;
                        continue;
                    }
                    
                    for (int k = 0; k <= i; k++) {
                        if (i - k - 1 >= 0 && !isSame(s[i - k - 1], p[j - 2])) {
                            break;
                        }
                        
                        if (f[i - k][j - 1]) {
                            f[i][j] = true;
                            break;
                        }
                    }
                    
                }
            }
        }
        
        return f[len_s][len_p];
    }
};