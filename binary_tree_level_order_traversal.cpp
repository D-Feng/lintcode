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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode *> l_queue;
        l_queue.push(root);
        
        while (!l_queue.empty()) {
            vector<int> level;
            int len_queue = l_queue.size();
            for (int i = 0; i < len_queue; i++) {
                level.push_back(l_queue.front()->val);
                if (l_queue.front()->left != NULL){
                    l_queue.push(l_queue.front()->left);
                }
                if (l_queue.front()->right != NULL){
                    l_queue.push(l_queue.front()->right);
                } 
                l_queue.pop();
                
            }
            result.push_back(level);
        }
        return result;
    }
};

