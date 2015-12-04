    int median(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return nums[( n - 1 )/2];
    }