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
    void compute(TreeNode* root,int number,int &sum){
        if(root==nullptr) return ;
        number=number*10+root->val;
        if(root->left==nullptr && root->right==nullptr){
            sum+=number;
            return;
        }
        compute(root->left,number,sum);
        compute(root->right,number,sum);
        return;

    }
    int sumNumbers(TreeNode* root) {
        int sum=0,number=0;
        compute(root,number,sum);
        return sum;
    }
};