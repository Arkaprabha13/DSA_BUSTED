#include <bits/stdc++.h>
using namespace std;

// Node structure for the AVL tree
struct Node {
    int data, height;
    Node *left, *right;
    Node(int x) {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to find the node with the minimum value in a given subtree
Node* findMinValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Function to perform a right rotation
Node* rotateRight(Node* currentNode) {
    Node* newRoot = currentNode->left;
    Node* newRootRightSubtree = newRoot->right;

    newRoot->right = currentNode;
    currentNode->left = newRootRightSubtree;

    currentNode->height = max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

// Function to perform a left rotation
Node* rotateLeft(Node* currentNode) {
    Node* newRoot = currentNode->right;
    Node* newRootLeftSubtree = newRoot->left;

    newRoot->left = currentNode;
    currentNode->right = newRootLeftSubtree;

    currentNode->height = max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

// Function to delete a node with a given key from the AVL tree
Node* deleteNode(Node* root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = (root->left) ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    // Update height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if needed

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Driver code
int main() {
    int t;
    cin >> t;
    getchar(); // Consume the newline character

    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        int n;
        cin >> n;
        int ip[n];
        for (int i = 0; i < n; i++)
            cin >> ip[i];

        for (int i = 0; i < n; i++) {
            root = deleteNode(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        if (root == NULL)
            cout << "null";
        else
            printInorder(root);
        cout << endl;

        getline(cin, s); // to deal with newline character
    }
    return 1;
}
