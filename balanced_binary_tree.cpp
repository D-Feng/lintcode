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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return maxDepth(root) != -1;
        
    }
    
    int maxDepth(TreeNode *node) {
        if(node == NULL) {
            return 0;
        }
        
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        
        if (leftDepth == -1 || rightDepth == -1 || std::abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        
        return std::max(leftDepth, rightDepth) + 1;
    }
};
