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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        
        vector<TreeNode*> path_a, path_b;
        
        if (dfsPath(path_a, root, A) && dfsPath(path_b, root, B)) {
            int i = 0;
            for (; i < path_a.size() && i < path_b.size(); i++) {
                if (path_a[i] != path_b[i]) {
                    return path_a[i - 1];
                }
            }
            if (i == path_a.size()) {
                return path_a[i - 1];
            }
            if (i == path_b.size()) {
                return path_b[i - 1];
            }
        }
        return NULL;
    }
    
    bool dfsPath(vector<TreeNode*> &path, TreeNode* root, TreeNode *A) {
        if (root == NULL) {
            return false;
        }
        if (root == A) {
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if (dfsPath(path, root->left, A))
            return true;
        if (dfsPath(path, root->right, A))
            return true;
        path.pop_back();
        return false;
    }
    
};
