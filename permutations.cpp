class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        vector<bool> used(nums.size(), false);
        vector<int> list;
        permuteHelper(result, list, used, nums);
        return result;
    }
    
    void permuteHelper(vector<vector<int>> &result, vector<int> &list, 
        vector<bool> &used, const vector<int> &num) {
        if (list.size() == num.size()) {
            result.push_back(list);
            return;
        }
        
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                list.push_back(num[i]);
                permuteHelper(result, list, used, num);
                list.pop_back();
                used[i] = false;
            }
        }
    }
    
};

