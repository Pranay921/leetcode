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
    int levels(TreeNode* root,int node,int level){
        if(root==nullptr) return 0;
        level++;
        if(root->val==node) return level;
        int leftt=levels(root->left,node,level);
        if(leftt) return leftt;
        int rightt=levels(root->right,node,level);
        if(rightt) return rightt;
        // level--;
        return 0;
    }
    TreeNode* parentFinder(TreeNode* root,int node){
        if(root==nullptr) return nullptr;
        if(root->left!=nullptr && root->left->val==node || root->right!=nullptr && root->right->val==node) return root;
        TreeNode* leftt=parentFinder(root->left,node);
        if(leftt) return leftt; 
        TreeNode* rightt=parentFinder(root->right,node);
        if(rightt) return rightt;
        return nullptr;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xParent=parentFinder(root,x);
        TreeNode* yParent=parentFinder(root,y);
        int l1=0,l2=0;
        int xLevel=levels(root,x,l1);
        int yLevel=levels(root,y,l2);
        if(xLevel==yLevel && xParent->val!=yParent->val) return true;
        return false;
    }
};