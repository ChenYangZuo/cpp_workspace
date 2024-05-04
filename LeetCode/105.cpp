//
// Created by zuo-c on 2024/4/2.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode *myBuildTree(const vector<int> &preorder, const vector<int> &inorder,
                          int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right || inorder_left > inorder_right) {
            return nullptr;
        }
        int preorder_root_index = preorder_left;
        int inorder_root_index = index[preorder[preorder_root_index]];

        TreeNode *root = new TreeNode(preorder[preorder_root_index]);
        int left_tree_size = inorder_root_index - inorder_left;
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + left_tree_size,
                                 inorder_left, inorder_left - 1);

        root->right = myBuildTree(preorder, inorder, preorder_left + left_tree_size + 1, preorder_right,
                                  inorder_root_index + 1, inorder_right);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 构建哈希表用来查询中序遍历中根节点的索引
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    void destroyTree(TreeNode* root) {
        if (root == nullptr) // 空节点，直接返回
            return;

        // 递归销毁左子树
        destroyTree(root->left);
        // 递归销毁右子树
        destroyTree(root->right);

        // 销毁当前节点
        delete root;
    }
};

int main() {
    auto s = Solution();
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    auto root = s.buildTree(preorder, inorder);
    s.destroyTree(root);
    return 0;
}