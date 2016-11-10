/**
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void BTPaths(TreeNode * root, vector<string>& ans, string path){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            path = path + to_string(root->val);
            ans.push_back(path);
            return;
        }
        path = path + to_string(root->val)+"->";
        BTPaths(root->left,ans,path);
        BTPaths(root->right,ans,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        BTPaths(root, ans,"");
        return ans;
    }
};