class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        if (nums.size() < 3) {
            return -1;
        }
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int diff = abs(target - result);
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int sum2 = twoSumClosest(nums, i + 1, target - nums[i]);
            if (abs(target - sum2 - nums[i]) < diff) {
                result = nums[i] + sum2;
                diff = abs(target - sum2 - nums[i]);
                if (diff == 0) {
                    return result;
                }
            }
        }
        return result;
    }


    int twoSumClosest(vector<int> &nums, int start, int target) {
        
        int head = start;
        int tail = nums.size() - 1;
        int result = nums[start] + nums[start + 1];
        int diff = abs(target - result);
        
        while(head < tail) {
            int sum = nums[head] + nums[tail];
            
            if (sum < target) {
                if (target - sum < diff) {
                    diff = target - sum;
                    result = sum;
                }
                head++;
            } else if (sum > target) {
                if (sum - target < diff) {
                    diff = sum - target;
                    result = sum;
                }
                tail--;
                
            } else {
                return target;
            }
        }
        return result;
    }
};
