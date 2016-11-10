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
    string getPath(TreeNode *root, map<TreeNode *, TreeNode *>mp){
        string path = "";
        stack<int> res;
        while(root){
            res.push(root->val);
            root = mp[root];
        }
        path = path + to_string(res.top());
        res.pop();
        while(!res.empty()){
            path = path + "->" +to_string(res.top());
            res.pop();
        }
        return path;
    }
    vector<string> BTPathsIterative(TreeNode * root){
        stack<TreeNode *> st;
        map<TreeNode *, TreeNode *> mp;
        vector<string> ans;
        if(root == NULL)
            return ans;
        st.push(root);
        mp[root] = NULL;
        while(!st.empty()){
            TreeNode * curr = st.top();
            st.pop();
            if(!curr->left && !curr->right){
                ans.push_back(getPath(curr,mp));
            }
            if(curr->right){
                mp[curr->right] = curr;
                st.push(curr->right);
            }
            if(curr->left){
                mp[curr->left] = curr;
                st.push(curr->left);
            }
        }
        return ans;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans = BTPathsIterative(root);
        // BTPaths(root, ans,"");
        
        return ans;
    }
};