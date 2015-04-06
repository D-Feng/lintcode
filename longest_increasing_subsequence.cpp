class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        // f[i] 元素i作为LIS最后一个元素的LIS的长度
        // f[i] = f[j] + 1 j [0..i - 1] && num[i] >= num[j]
        
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> f(len, 1);
        int lis_length = 1;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] >= nums[j]) {
                    f[i] = max(f[j] + 1, f[i]);
                    if (f[i] > lis_length) {
                        lis_length = f[i];
                    }
                }
            }
        }
        return lis_length;
    }
};