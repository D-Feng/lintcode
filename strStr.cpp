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
        if(source == NULL || target == NULL) {
            return -1;
        }
            
        string src(source);
        string tar(target);
        int i, j;
        for(i = 0; i < src.length() - tar.length() + 1; i++ ) {
            for(j = 0; j < tar.length(); j++) {
                if(src[i+j] != tar[j]) {
                    break;
                }
            }
            if(j == tar.length()) {
                return i;
            }
        }
        
        return -1;
    }
};

