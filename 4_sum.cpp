class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int n = nums.size();
        vector<vector<int>> result;
        unordered_map<int, vector<pair<int, int>>> pairs;
        pairs.reserve(n * n);
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                pairs[nums[i] + nums[j]].push_back(make_pair(i, j));    
            }
        }
        
        
        for (int i = 0; i < n - 3; i++) {
            //avoid duplication
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                //avoid duplication
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int curSum = nums[i] + nums[j];
                
                if (pairs.find(target - curSum) != pairs.end()) {
                    
                    vector<pair<int, int>> &sum2 = pairs[target - curSum];
                    
                    bool isFirstPush = true;
                    for (auto &it : sum2) {
                        //avoid duplication and make index ascending
                        if (it.first <= j) {
                            continue;
                        }
                        if (isFirstPush || result.back()[2] != nums[it.first]) {
                            result.push_back(vector<int> {nums[i], nums[j], nums[it.first], nums[it.second]});
                            isFirstPush = false;
                        }
                    }
                    
                }
            }
        }
        
        return result;
    }
};
