class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s1, const char *p1) {
        // write your code here
        string s(s1);
        string p(p1);
        // f[i][j] first i elements of s and first j elements of p 
        
        // f[0][0] = true
        // f[i][j] = f[i - 1][j - 1] if s[i - 1] == p[j - 1]
        // s[i - 1] == p[j - 1]
        
        // p[j - 1] = ? that s[i = 1] == p[j - 1]
        
        // if s[i - 1] == * for (j [0...j], if (f[i - 1][k] == true, f[i - 1][k..] = true))
        // then f[i - 1] 
        int len_s = s.size();
        int len_p = p.size();
        
        vector<vector<bool>> f(len_s + 1, vector<bool>(len_p, false));
        f[0][0] = true;
        for (int i = 1; i < len_s + 1; i++) {
            f[i][0] = false;
        }
        
        for (int i =  0; i < len_s + 1; i++) {
            for (int j = 1; j < len_p + 1; j++) {
                if (!f[i][j]) {
                    if (i - 1 >=0  && ( s[i - 1] == p[j - 1] ||  p[j - 1] == '?')) {
                        f[i][j] = f[i - 1][j - 1];
                    } else if (p[j - 1] == '*') {
                        // 遇到通配符
                        for (int k = 0; k <= i; k++) {
                            if (f[k][j - 1]) {
                                for (;k < len_s + 1; k++) {
                                    f[k][j] = true;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return f[len_s][len_p];
    }
};
