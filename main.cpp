#include <iostream>
using namespace std;

// Structure for the Node of the BST
struct Node {
    int data;         // Data of the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child

    // Constructor to initialize a new node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to search for a key in the BST
Node* search(Node* root, int key) {
    // If root is NULL or key is present at root
    if (root == nullptr || root->data == key)
        return root;

    // Key is greater than root's key
    if (key < root->data)
        return search(root->left, key);  // Search in left subtree
    else
        return search(root->right, key); // Search in right subtree
}

// Function to insert a new node in the BST
Node* insert(Node* root, int key) {
    // Create the new node to be inserted
    Node* newNode = new Node(key);

    // If the tree is empty, return the new node as the root
    if (root == nullptr)
        return newNode;

    // Initialize parent and current nodes
    Node* parent = nullptr;
    Node* current = root;

    // Traverse the tree to find the insertion point
    while (current != nullptr) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    // Insert the new node as a child of the parent node
    if (key < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Function to find the minimum value node in the BST
Node* minimum(Node* node) {
    // Traverse to the leftmost leaf
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// Function to find the maximum value node in the BST
Node* maximum(Node* node) {
    // Traverse to the rightmost leaf
    while (node->right != nullptr)
        node = node->right;
    return node;
}

// Function to find the inorder successor of a node in the BST
Node* successor(Node* root, Node* node) {
    // If right subtree is not null, successor is the minimum of right subtree
    if (node->right != nullptr)
        return minimum(node->right);

    // Otherwise, the successor is one of the ancestors
    Node* succ = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return succ;
}

// Function to find the inorder predecessor of a node in the BST
Node* predecessor(Node* root, Node* node) {
    // If left subtree is not null, predecessor is the maximum of left subtree
    if (node->left != nullptr)
        return maximum(node->left);

    // Otherwise, the predecessor is one of the ancestors
    Node* pred = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return pred;
}

// Function to perform in-order traversal of the BST (left-root-right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to perform pre-order traversal of the BST (root-left-right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform post-order traversal of the BST (left-right-root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function to delete a node in the BST
Node* deleteNode(Node* root, int key) {
    // Base case: if the tree is empty
    if (root == nullptr) return root;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
        // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
        // If key is same as root's key, then this is the node to be deleted
    else {
        // Case 1: Node with no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

            // Case 2: Node with only one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

            // Case 3: Node with two children
        else {
            // Find the inorder successor (smallest in the right subtree)
            Node* temp = minimum(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Main function to demonstrate the BST operations
int main() {
    // Create the root of the BST
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);

    // Print the BST in different orders
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Search for a node in the BST
    Node* searchResult = search(root, 40);
    if (searchResult)
        cout << "Found node with key 40" << endl;
    else
        cout << "Node with key 40 not found" << endl;

    // Delete nodes from the BST and print the in-order traversal after each deletion
    root = deleteNode(root, 20);
    cout << "Inorder traversal after deleting 20: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "Inorder traversal after deleting 30: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "Inorder traversal after deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
