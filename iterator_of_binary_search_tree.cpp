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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        index = 0;
        m_array.clear();
        dfs(root, m_array);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        if (index < m_array.size()) {
            return true;
        }
        return false;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code her
        if (hasNext())
            return m_array[index++];
        return NULL;
    }
    
private:
    vector<TreeNode*> m_array;
    int index;
    void dfs(TreeNode* root, vector<TreeNode*> &result) {
        if (root == NULL) {
            return;
        }
        dfs(root->left, result);
        result.push_back(root);
        dfs(root->right, result);
    }
    
};
