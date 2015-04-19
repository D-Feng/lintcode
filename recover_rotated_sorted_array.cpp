class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len == 0) {
            return;
        }
        int min_ind = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                min_ind = i + 1;
                break;
            }
        }
        if (min_ind = 0) {
            return;
        }
        
        for (int i = min_ind; i <= (min_ind + len - 1) / 2; i++) {
            swap(nums[i], nums[len - 1 + min_ind - i]);
        }
        
        for (int i = 0; i <= (len - 1) / 2; i++) {
            swap(nums[i], nums[len - 1 - i]);
        }
    }
    void swap(int &a; int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
