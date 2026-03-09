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
    TreeNode* build(vector<int> &nums,int start,int end){
        if(start>end) return nullptr;
        int idMax=start;
        for(int i=start+1;i<=end;i++){
            if(nums[i]>nums[idMax]) idMax=i;
        }
        TreeNode* root=new TreeNode(nums[idMax]);
        root->left=build(nums,start,idMax-1);
        root->right=build(nums,idMax+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0) return nullptr;
        int start=0,end=nums.size()-1;
        return build(nums,start,end);
    }
};