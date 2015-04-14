class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        int len = nums.size();
        if (len == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        vector<int> candidate;
        vector<bool> used(len, false);
        helper(result, candidate, used, nums);
        return result;
        
    }
    
    void helper(vector<vector<int>> &result, vector<int> &candidate, \
        vector<bool> &used, const vector<int> &nums) {
        if (candidate.size() == nums.size()) {
            result.push_back(candidate);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (i != 0 && nums[i - 1] == nums[i] && !used[i - 1]) {
                    continue;
                }
                used[i] = true;
                candidate.push_back(nums[i]);
                helper(result, candidate, used, nums);
                candidate.pop_back();
                used[i] = false;
            }
        }
    }
};
