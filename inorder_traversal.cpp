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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        helper(result, root);
        return result;
    }
    
private:
    void helper(vector<int> &result, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        helper(result, root->left);
        result.push_back(root->val);
        helper(result, root->right);
    }
};
