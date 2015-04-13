class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x <= 1) {
            return 0;
        }
        
        int start = 1;
        int end = x;
        int mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            // bug: mid * mid exceed the limit of INT
            if (x / mid == mid) {
                return mid;
            } else if (mid < x / mid ) {
                start = mid;
            } else if (mid > x / mid) {
                end = mid;
            }
        }
        if (end * end == x) {
            return end;
        }
        return start;
    }
};
