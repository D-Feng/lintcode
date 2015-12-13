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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> result;
        vector<int> current;
        
        if (root == NULL) {
            return result;
        }
        
        helper(result, root, current, 0, target);
        
        return result;
    }
    
    void helper(vector<vector<int>> &result, TreeNode *node, vector<int> &current, int sum, int target) {
        
        current.push_back(node->val);
        sum +=  node->val;
        
        if (node->left == NULL && node->right == NULL) {
            if (sum == target) {
                result.push_back(current);
            }
            return;
        }
        
        if (node->left) {
            helper(result, node->left, current, sum, target);
            current.pop_back();
            
        }
        if (node->right) {
            helper(result, node->right, current, sum, target);
            current.pop_back();
        }
        
    }
    
};