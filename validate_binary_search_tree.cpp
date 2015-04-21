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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return true;
        }
        
        if (root->left != NULL && root->val <= root->left->val) {
            return false;
        }
        if (root->right != NULL && root->val >= root->right->val) {
            return false;
        }
        
        return isValidBST(root->left) && isValidBST(root->right);
        
        
        
    }
};
