class Solution {
private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = height(root->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};