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
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return 0;
        }
        
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        
        return max(left_depth, right_depth) + 1;
        
    }
};
