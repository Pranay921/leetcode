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
    TreeNode* prev=nullptr;
    TreeNode* firstViolation=nullptr;
    TreeNode* nextFirst=nullptr;
    TreeNode* secondViolation =nullptr;
    TreeNode* compute(TreeNode* root){
        if(root==nullptr) return nullptr;
        compute(root->left);
        if(prev!=nullptr && (prev->val>root->val)){
            if(firstViolation==nullptr){
                firstViolation=prev;
                nextFirst=root;
            }
            else{
                secondViolation=root;
            }
        }
        prev=root;
        compute(root->right);
        return root;
    }
    void recoverTree(TreeNode* root) {
        compute(root);
        if(firstViolation!=nullptr && secondViolation!=nullptr) swap(firstViolation->val,secondViolation->val);
        else swap(firstViolation->val,nextFirst->val);
    }
};