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
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int leftr = height(root->left);
        if(leftr == -1) return -1;
        int rightr = height(root->right);
        if(rightr == -1) return -1;

        if(abs(rightr - leftr) > 1){
            return -1;
        }

        return 1 + max(leftr, rightr);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        return height(root) != -1;
    }
};
