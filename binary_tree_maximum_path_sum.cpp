/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        pair<int, int> result = helper(root);
        return result.second;
    }
    
    // 2 condition with root, without root
    // return type : single path, max path
    pair<int, int> helper(TreeNode *node) { 
        if (node == NULL) {
            return pair<int, int> (0, -INT_MAX);
        }
        // divide
        pair<int, int> left_result = helper(node->left);
        pair<int, int> right_result = helper(node->right);
        
        // conquer
        int single_max = max(left_result.first, right_result.first);
        single_max += node->val;
        single_max = max(0, single_max);
        
        int maximum = max(left_result.second, right_result.second);
        maximum = max(maximum, left_result.first + right_result.first + node->val);
        
        return pair<int, int> (single_max, maximum);
    }
};
