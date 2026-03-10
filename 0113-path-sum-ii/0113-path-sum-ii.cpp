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
    int compute(int s,TreeNode* root,int target,vector<int>ans,vector<vector<int>> &result ){
        if(root==nullptr) return 0;
        s+=root->val;
        ans.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && s==target){
            result.push_back(ans);
            // ans.pop_back();
        }
        compute(s,root->left,target,ans,result);
        compute(s,root->right,target,ans,result);
        return s;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        int s=0;
        vector<vector<int>>result;
        compute(s,root,targetSum,ans,result);
        return result;
    }
};