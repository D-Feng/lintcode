class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1) {
            return;
        }
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                reverse(nums, 0, i);
                reverse(nums, i + 1, nums.size() - 1);
                reverse(nums, 0, nums.size() - 1);
                break;
            }
        }
    }
    
private:
    void reverse(vector<int> &nums, int start, int end) {
        int i, j;
        for (i = start, j = end; i < j ; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    
};
