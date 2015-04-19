class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        string src(source);
        string tar(target);
        int len_s = src.size();
        int len_t = tar.size();
        if (len_s < len_t || len_s == 0 || len_t == 0) {
            return -1;
        }
        
        for (int i = 0; i < len_t - len_s + 1; i++) {
            for (int j = 0; j < len_t; j++) {
                if (src[i + j] != tar[j]) {
                    break;
                }
                if (j == len_t - 1) {
                    return j;
                }
            }
        }
        
        return -1;
    }
};

