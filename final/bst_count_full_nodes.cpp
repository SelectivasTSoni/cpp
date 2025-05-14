// bst_count_full_nodes.cpp

// 5) Given a binary tree, find the count of full nodes in it. A full node has non-null left and right children. Use the tree: [5, 3, 8, 1, 4, null, 10]

// no similiar previous problem

#include <iostream>
#include <vector>
#include <optional>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Builds a binary tree from level-order array with std::nullopt for nulls
TreeNode* buildTreeFromArray(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value()) return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        ++i;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        ++i;
    }

    return root;
}

// Count full (2-child) nodes
int countFullNodes(TreeNode* root) {
    if (!root) return 0;
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->left && node->right) count++;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return count;
}

int main() {
    vector<optional<int>> input = {
        5, 3, 8, 9, 1, 4, nullopt, 10
    };

    TreeNode* root = buildTreeFromArray(input);
    cout << "Full node count: " << countFullNodes(root) << endl;

    return 0;
}
