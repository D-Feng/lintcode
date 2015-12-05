class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    //     int naive(vector<int> &nums) {
    //     // write your code here
    //     int n = nums.size();
    //     if (n == 0) {
    //         return 0;
    //     }
    //     sort(nums.begin(), nums.end());
    //     return nums[( n - 1 )/2];
    // }
    
    void swap(vector<int> &nums, int a, int b) {
    	int temp = nums[a];
    	nums[a]	= nums[b];
    	nums[b] = temp;
    }
    
    int findKSmall(vector<int> &nums, int k, int start, int end) {

    	int pivot = end;
    	int l = start;
    	int r = end;
    	while (true) {
    		while (nums[l] <= nums[pivot] && l < r) {
    			l++;
    		}
    		while (nums[pivot] <= nums[r] && l < r) {
    			r--;
    		}
    		if (r == l) break;
    		swap(nums, l, r);
    	}

    	swap(nums, l, pivot);

    	if (l == k) return nums[l];

    	if (l < k) return findKSmall(nums, k, l + 1, end);

    	return findKSmall(nums, k, start, l - 1);
    }





    int median(vector<int> &nums) {

    	int n = nums.size();
        if (n == 0) {
            return 0;
        }
        return findKSmall(nums, ( n - 1 )/2, 0, n - 1);
    }





};

