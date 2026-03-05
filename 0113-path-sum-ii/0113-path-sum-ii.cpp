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
    void inOrder(TreeNode* root,int sum,int target,vector<int> ans,vector<vector<int>> &path){
        if(root==nullptr) return;
        sum+=root->val;
        ans.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
             if(sum==target){
                path.push_back(ans);
             }
            //  ans.pop_back();
             return;
        }
        if(root->left) inOrder(root->left,sum,target,ans,path);
        if(root->right) inOrder(root->right,sum,target,ans,path);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        vector<vector<int>> path;
        inOrder(root,0,targetSum,ans,path);
        return path;
    }
};