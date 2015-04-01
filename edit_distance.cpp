class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        // f[i][j] i characters in word1, j characters in word2 min distance
        // f[0][j] = j;
        // f[i][0] = i;
        // last status to f[i][j]
        // insert: f[i][j] = f[i][j - 1] + 1;
        // replace: f[i][j] = f[i - 1]f[j - 1] + 1 
                    //f[i - 1][j - 1] if word1[i + 1] == word2[j + 1]
        // delele: f[i][j] = f[i - 1][j] + 1
        int len_word1 = word1.size();
        int len_word2 = word2.size();
        vector<vector<int>> f(len_word1 + 1, vector<int>(len_word2 + 1, 0));
        for (int i = 1; i < len_word1 + 1; i++) {
            f[i][0] = i;
        }
        for (int j = 1; j < len_word2 + 1; j++) {
            f[0][j] = j;
        }
        
        for (int i = 1; i < len_word1 + 1; i++) {
            for (int j = 1; j < len_word2 + 1; j++) {
                int temp1 = f[i][j - 1] + 1;
                int temp2 = f[i - 1][j - 1] + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    temp2 -= 1;
                }
                int temp3 = f[i - 1][j] + 1;
                temp1 = min(temp1, temp2);
                f[i][j] = min(temp1, temp3);
            }
        }
        
        return f[len_word1][len_word2];
    }
};

