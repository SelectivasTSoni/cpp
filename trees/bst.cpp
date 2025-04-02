// bst.cpp

#include <iostream>
#include <vector>
using namespace std;

// Definition of a BST node
struct Node 
{
    int data;
    Node* left;
    Node* right;
    
    Node(int value) 
    {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node into BST
Node* insert(Node* root, int data) 
{
    if (root == nullptr) 
    {
        return new Node(data);
    }
    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } else 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) 
{
    while (root->left != nullptr) 
    {
        root = root->left;
    }
    return root;
}

// Function to print all root-to-leaf paths
void printPaths(Node* root, vector<int>& path) 
{
    if (root == nullptr) 
    {
        return;
    }
    
    // Add current node to path
    path.push_back(root->data);
    
    // If it's a leaf node, print the path
    if (root->left == nullptr && root->right == nullptr) 
    {
        for (int val : path) 
        {
            cout << val << " ";
        }
        cout << endl;
    } 
    else 
    {
        // Recur for left and right subtrees
        printPaths(root->left, path);
        printPaths(root->right, path);
    }
    
    // Remove the current node to backtrack
    path.pop_back();
}

// Function to search for a key in the BST
bool search(Node* root, int key) 
{
    if (root == nullptr) 
    {
        return false;
    }
    if (root->data == key) 
    {
        return true;
    } 
    else if (key < root->data) 
    {
        return search(root->left, key);
    } 
    else 
    {
        return search(root->right, key);
    }
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int key) 
{
    if (root == nullptr) 
    {
        return root;
    }
    if (key < root->data) 
    {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) 
    {
        root->right = deleteNode(root->right, key);
    } 
    else 
    {
        // Node with only one child or no child
        if (root->left == nullptr) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



// Function to find the nth smallest element in BST
void findNthSmallest(Node* root, int& n, int& result) 
{
    if (root == nullptr || n <= 0) 
    {
        return;
    }
    
    // Inorder traversal (Left, Root, Right)
    findNthSmallest(root->left, n, result);
    
    n--;
    if (n == 0) 
    {
        result = root->data;
        return;
    }
    
    findNthSmallest(root->right, n, result);
}




int main() 
{
    vector<int> arr = {17, 29, 15, 33, 44, 43, 13, 46, 49, 18};
    Node* root = nullptr;
    
    // Construct the BST
    for (int num : arr) 
    {
        root = insert(root, num);
    }
    

    // Print all root-to-leaf paths
    cout << "*******************************" << endl;
    cout << "Print all root-to-leaf paths: " << endl;
    cout << "*******************************" << endl;
    vector<int> path;
    cout << "Root-to-Leaf Paths in BST:" << endl;
    printPaths(root, path);
    cout << endl;
    
    // Search for a key in BST
    cout << "*******************************" << endl;
    cout << "Search for a key in BST: " << endl;
    cout << "*******************************" << endl;
    int key = 44; // Example key to search
    if (search(root, key)) 
    {
        cout << "Key " << key << " exists in BST." << endl;
    } 
    else 
    {
        cout << "Key " << key << " does not exist in BST." << endl;
    }
    // Search another for a key in BST
    int next_key = 92; // Example key to search
    if (search(root, next_key)) 
    {
        cout << "Key " << next_key << " exists in BST." << endl;
    } 
    else 
    {
        cout << "Key " << next_key << " does not exist in BST." << endl;
    }
    cout << endl;

    // Delete a key from BST
    cout << "*******************************" << endl;
    cout << "Delete a key from BST: " << endl;
    cout << "*******************************" << endl;
    int deleteKey = 33; // Example key to delete
    root = deleteNode(root, deleteKey);
    cout << "After deleting key " << deleteKey << ":" << endl;
    printPaths(root, path);
    cout << endl;

    // Find nth smallest element
    cout << "*******************************" << endl;
    cout << "Find nth smallest element in BST: " << endl;
    cout << "*******************************" << endl;
    vector<int> new_arr = {5, 4, 7, 2, 4, 6, 8};
    Node* new_root = nullptr;
    
    // Construct a new BST using new_arr
    for (int num : new_arr) 
    {
        new_root = insert(new_root, num);
    }

    int n = 3; // Find 3rd smallest element
    int result = -1;
    findNthSmallest(new_root, n, result);
    if (result != -1) 
    {
        cout << "The " << 3 << "rd smallest element in the BST is: " << result << endl;
    } 
    else 
    {
        cout << "\nThe BST does not have " << 3 << " elements." << endl;
    }
    cout << endl;
    
    return 0;
}