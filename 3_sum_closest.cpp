class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        
        vector<int> path;
        
        return helper(nums, path, 0, target);
        
    }
    
    
    
    int helper(vector<int> &nums, vector<int> &path, int ind, int target) {
        if (path.size() == 3) {
            return accumulate(path.begin(), path.end(), 0);
        }
        
        int closest = INT_MAX;
        
        for (int i = ind; i < nums.size(); i++) {
            path.push_back(nums[i]);
            int temp = helper(nums, path, i + 1, target);
            if (temp == target) {
                return target;
            }
            closest = abs(target - temp) < abs(target - closest) ? temp: closest;
            path.pop_back();
            
        }
        
        return closest;
    }
};
