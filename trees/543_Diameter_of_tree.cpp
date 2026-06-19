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
    int ans;
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int leftd = height(root->left);
        int rightd = height(root->right);

        ans = max(ans, leftd + rightd);

        return 1 + max(leftd, rightd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        height(root);
        return ans;
    }
};
