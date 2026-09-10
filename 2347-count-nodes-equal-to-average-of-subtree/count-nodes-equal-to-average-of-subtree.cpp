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
int totalcount=0;
    pair<int,int> count_average(TreeNode* root){
        if(!root) return {0,0};

        auto a=count_average(root->left);
        auto b=count_average(root->right);

        pair<int,int> res;

        res.first=root->val + a.first + b.first;
        res.second=1 + a.second + b.second;

        int average=res.first/res.second;

        totalcount+=(average==root->val);

        return res;
    }
    int averageOfSubtree(TreeNode* root) {
        count_average(root);

        return totalcount;
    }
};