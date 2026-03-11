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
unordered_map<int,int> mp;
int postIndex=0;
    TreeNode* compute(vector<int> &postorder,int left,int right){
        if(left>right) return nullptr;
        int rootval=postorder[postIndex++];
        TreeNode* root=new TreeNode(rootval);
        int index=mp[rootval];
        root->right=compute(postorder,index+1,right);
        root->left=compute(postorder,left,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return compute(postorder,0,postorder.size()-1);
    }
};