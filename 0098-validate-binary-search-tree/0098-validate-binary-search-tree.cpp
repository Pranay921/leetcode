// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int leftMax(TreeNode* root){
//         if(root==nullptr) return INT_MIN;
//         int mx=root->val;
//         int leftt=leftMax(root->left);
//         if(leftt>mx) mx=leftt;
//         int rightt=leftMax(root->right);
//         if(rightt>mx) mx=rightt;
//         return mx;
//     }
//     int rightMin(TreeNode* root){
//         if(root==nullptr) return INT_MAX;
//         int mn=root->val;
//         int leftt=rightMin(root->left);
//         if(leftt<mn) mn=leftt;
//         int rightt=rightMin(root->right);
//         if(rightt<mn) mn =rightt;
//         return mn;
//     }
//     bool isValidBST(TreeNode* root) {
//         if(root==nullptr) return true;
//         if(root->left!=nullptr && root->val<=leftMax(root->left)) return false;
//         if(root->right!=nullptr && root->val>=rightMin(root->right)) return false;
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };
class Solution {
public:

    bool check(TreeNode* root, long long mn, long long mx){
        if(root == nullptr) return true;

        if(root->val <= mn || root->val >= mx) return false;

        return check(root->left, mn, root->val) && 
               check(root->right, root->val, mx);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};