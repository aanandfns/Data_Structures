class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q != nullptr) return 0;
        if(p != nullptr && q == nullptr) return 0;
        if(p == nullptr && q == nullptr) return 1;
        if(p->val != q->val) return 0;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};