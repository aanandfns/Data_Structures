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

    int b_i(string s) {
        int ans = 0;
        for(char c : s) {
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }

    void helper(TreeNode* root, string temp, vector<string>& ans) {
        if(!root) return;

        temp += to_string(root->val);

        if(!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);

        int res = 0;
        for(string &s : ans) {
            res += b_i(s);
        }

        return res;
    }
};