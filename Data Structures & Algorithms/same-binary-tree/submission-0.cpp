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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are empty then they are the same
        if (p == nullptr && q == nullptr) {
                return true;
        }

        // This catches the case after &&-condition if only one is empty
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // If the values are not the same, return false
        if (q->val != p->val) {
            return false;
        }

        // Repeat for each node
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
