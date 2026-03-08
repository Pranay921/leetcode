/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) return root;
        TreeNode* leftt=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightt=lowestCommonAncestor(root->right,p,q);
        if(leftt==nullptr){
            return rightt;
        }
        else if(rightt==nullptr){
            return leftt;
        }
        else{
            return root;
        }

    }
};