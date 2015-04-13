class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int len = num.size();
        if (len == 0) {
            return -1;
        }
        int min = num[0];
        for (int i = 1; i < len; i++) {
            if (num[i] < min) {
                min = num[i];
            }
        }
        return min;
    }
};
