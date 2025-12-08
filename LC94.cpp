// TC : O(n) ~ Traversing each nodes only once
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {
        if(root) {
            helper(root->left, ans);
            ans.push_back(root->val);
            helper(root->right, ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};