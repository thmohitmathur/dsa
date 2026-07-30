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
    int sum = 0;
    int maxe = INT_MIN;

    int doso(TreeNode* root){
        if(root == nullptr) return 0;
        int leftm = max(0, doso(root->left));
        int rightm = max(0, doso(root->right));

        int currsum = root->val + leftm + rightm;

        maxe = max(currsum, maxe);

        return root->val + max(leftm, rightm);
    }
public:
    int maxPathSum(TreeNode* root) {
     maxe = INT_MIN;

        doso(root);



        return maxe;
    }
};
