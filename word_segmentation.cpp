class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        // write your code here
        // f[i] whether first i elmenets of s can be divided into words of dict
        // f[0][j] = false; f[i][0] = false
        // f[i] = f[i - 1] if A[i - 1] in dict
        
        int len = s.size();
        if (len == 0) {
            return true;
        }

        bool chs[256] = {false};
        for (unordered_set<string>::iterator it=dict.begin(); \
             it!=dict.end(); ++it) {
            string word = *it;
            for (size_t i=0; i<word.size(); ++i) {
                chs[static_cast<int>(word[i])] = true;
            }
        }
        for (size_t i=0; i<s.size(); ++i) {
            if (!chs[static_cast<int>(s[i])]) {
                return false;
            }
        }

        vector<bool> f(len + 1, false);
        f[0] = true;
        
        for (int i = 1 ; i < len + 1; i++) {
            for (int j = 1; j <= i; j++) {
                bool temp = f[i - j];
                if (temp && dict.find(s.substr(i - j, j)) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};
