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
    int doSome(TreeNode* root, int maxs){
        if(root == nullptr) return 0;
        int count = 0;

        if(maxs <= root->val){
            count = 1;
        }
        maxs = max(maxs, root->val);
        count += doSome(root->left, maxs);
        count += doSome(root->right, maxs);

        return count;
    }
    int goodNodes(TreeNode* root) {

        return doSome(root, root->val);

    }
};
d

