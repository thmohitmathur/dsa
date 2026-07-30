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
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>&inorder, int left, int right, unordered_map<int, int>& mp){

        if(left > right){
            return nullptr;
        }

        TreeNode*  root = new TreeNode(preorder[preIndex++]);

        int mid = mp[root->val];

        root->left =  build(preorder, inorder, left, mid -1 , mp);
        root->right = build(preorder, inorder, mid + 1, right, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size()-1, mp);
    }
};

