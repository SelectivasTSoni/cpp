// bst_mirror.cpp

// 1) Given a binary tree, create a new tree that is a mirror image of the original tree. Use the tree: [5, 3, 8, 1, 4, null, 10]

// no similar previous problem

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursively mirror the binary tree
TreeNode* mirror(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* mirrored = new TreeNode(root->val);
    mirrored->left = mirror(root->right);
    mirrored->right = mirror(root->left);
    return mirrored;
}

// Helper: print tree level-order
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    // Track when the last non-null node was seen
    bool hasMoreNodes = true;

    while (!q.empty() && hasMoreNodes) {
        int levelSize = q.size();
        hasMoreNodes = false; // Assume this is the last level

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur) {
                cout << cur->val << " ";
                q.push(cur->left);
                q.push(cur->right);

                // If any children are non-null, continue further levels
                if (cur->left || cur->right) {
                    hasMoreNodes = true;
                }
            } else {
                cout << "null ";
                q.push(nullptr); // Maintain structure
                q.push(nullptr);
            }
        }
    }

    cout << endl;
}


// Construct original tree from the given structure
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(10);
    return root;
}

// Print the tree in ASCII-art rotated format
void printAsciiTree(TreeNode* root, int space = 0, int indent = 5) {
    if (!root) return;

    space += indent;

    // Print right child first (so it appears on top)
    printAsciiTree(root->right, space);

    // Print current node after spacing
    //cout << endl;
    for (int i = indent; i < space; ++i) cout << " ";
    cout << root->val << "\n";

    // Then print left child
    printAsciiTree(root->left, space);
}



int main() {
    TreeNode* original = buildSampleTree();
    cout << "Original Tree: ";
    printLevelOrder(original);
    cout << "Original Tree ASCII:\n";
    printAsciiTree(original);               // Print ASCII art

    TreeNode* mirrored = mirror(original);
    cout << "Mirrored Tree: ";
    printLevelOrder(mirrored);
    cout << "Mirrored Tree ASCII:\n";
    printAsciiTree(mirrored);               // Print ASCII art

    return 0;
}
