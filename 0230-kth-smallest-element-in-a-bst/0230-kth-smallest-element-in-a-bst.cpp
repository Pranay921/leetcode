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
    int kthSmallest(TreeNode* root, int k) {
       vector<int> nums; 
       preOrder(root,nums);
       priority_queue<int,vector<int>,greater<int>> q;
       for(auto i:nums){
        q.push(i);
       }
       for(int i=1;i<k;i++){
        q.pop();
       }
       return q.top();
    }
    void preOrder(TreeNode* root,vector<int>&nums){
         if(root==NULL) return;
            nums.push_back(root->val);
            preOrder(root->left,nums);
            preOrder(root->right,nums);
    }
};