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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
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
        helper(result, root->right);
        result.push_back(root->val);
    }
};
