class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int len = num.size();
        if (len == 0) {
            return -1;
        }
        if (len == 1) {
            return num[0];
        }
        
        int start = 0;
        int end = len - 1;
        int mid;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (num[start] < num[mid] && num[mid] < num[end]) {
                return num[start];
            } else if (num[mid] > num[start]) {
                start = mid;
            } else if (num[mid] < num[start]) {
                end = mid;
            }
        }
        return num[start] < num[end] ? num[start] : num[end];
        
    }
};
