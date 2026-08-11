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
    int dia=0;
    int level(TreeNode* root){
        if(root==NULL) return 0;
        // if(root->left ==NULL || root->right==NULL) return 1;
        int left=level(root->left);
        int right=level(root->right);
        dia=max(dia,left+right);
        return 1+max(left,right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        level(root);
        return dia;
    }
};