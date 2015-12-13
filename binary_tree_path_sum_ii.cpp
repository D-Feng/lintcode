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
     * @param root the root of binary tree.
     * @return an integer
     */
     
    
    int maxPathSum2(TreeNode *root) {
        // Write your code here
        
        if (root == NULL) {
            return 0;
        }
        vector<int> path;
        
        int result = helper(root, path);
        if (path.size() == 0) {
            return root->val;
        }
        return result;
        
    }
    
    int helper(TreeNode *node, vector<int> &path) {
        
        if (node == NULL) {
            return 0;
        }
        
        int max_left = helper(node->left, path);
        int max_right = helper(node->right, path);
        
        int m_max = max(max_left, max_right);
        m_max += node->val;
        
        if (m_max >= 0) {
            path.push_back(node->val);
        } else {
            path.clear();
        }
        
        return max(0, m_max);
    }
    
};