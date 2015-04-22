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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> result;
        helper(result, root, k1, k2);
        return result;
    }
private: 
    void helper(vector<int> &result, TreeNode* root, int k1, int k2) {
        if (root == NULL) {
            return;
        }
        helper(result, root->left, k1, k2);
        if (root->val >= k1 && root->val <= k2) {
            result.push_back(root->val);
        }
        helper(result, root->right, k1, k2);
    }
};
