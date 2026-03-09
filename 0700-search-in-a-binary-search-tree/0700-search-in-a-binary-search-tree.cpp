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
    TreeNode* checker(TreeNode* root,int val){
        if(root==nullptr) return nullptr;
        if(root->val==val) return root;
        if(val<root->val) return checker(root->left,val);
        else return checker(root->right,val);
        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return nullptr;
        if(checker(root,val)){
            return checker(root,val);
        }
        else{
            return nullptr;
        }
    }
};