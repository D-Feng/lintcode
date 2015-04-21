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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        helper(result, root);
        return result;
    }
    
private:
    void helper(vector<int> &result, TreeNode *root) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->val);
        helper(result, root->left);
        helper(result, root->right);
    }
};

