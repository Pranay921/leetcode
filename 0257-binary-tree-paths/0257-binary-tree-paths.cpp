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
    void compute(TreeNode* root,string result,vector<string> &finalResult){
        if(root==nullptr) return ;
        if(result=="") result=to_string(root->val);
        else result+="->"+to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            finalResult.push_back(result);
            return;
        }
        compute(root->left,result,finalResult);
        compute(root->right,result,finalResult);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string result="";
        vector<string> finalResult;
        compute(root,result,finalResult);
        return finalResult;
    }
};