/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void doSome(int lvl, TreeNode* root, int& depth){
        if(root == nullptr){
            return;
        }
        depth = max(lvl, depth);
            
        doSome(lvl + 1, root->left, depth);
        doSome(lvl + 1, root->right, depth);

    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int depth = 0;
        doSome(1, root, depth);
        return depth;
    }
};
