#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to rotate a subtree to the right
struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return the new root
    return x;
}

// Function to rotate a subtree to the left
struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a new node in an AVL tree
struct Node* insertNode(struct Node* root, int data) {
    // Perform the normal BST insertion
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else // Duplicate keys are not allowed
        return root;

    // Update the height of the current node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Check the balance factor and perform rotations if necessary
    int balanceFactor = getBalanceFactor(root);

    // Left-Left case
    if (balanceFactor > 1 && data < root->left->data)
        return rotateRight(root);

    // Right-Right case
    if (balanceFactor < -1 && data > root->right->data)
        return rotateLeft(root);

    // Left-Right case
    if (balanceFactor > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right-Left case
    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Return the unchanged root
    return root;
}

// Function to find the minimum value node in an AVL tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from an AVL tree
struct Node* deleteNode(struct Node* root, int data) {
    // Perform the normal BST deletion
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            // No child or one child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp;

            free(temp);
        } else {
            // Two children case
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node or the node was not found, return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Check the balance factor and perform rotations if necessary
    int balanceFactor = getBalanceFactor(root);

    // Left-Left case
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left-Right case
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right-Right case
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right-Left case
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Return the unchanged root
    return root;
}

// Function to print the tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
// Function to print the tree in preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to print the tree in postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Driver code
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("AVL Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3.  inorder traversal\n");
        printf("4.  preorder traversal\n");
        printf("5.  postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                struct Node* originalRoot = root;  // Store the original root
                root = deleteNode(root, data);
                if (root == originalRoot) {
                    printf("Node not present in the tree.\n");
                } else {
                    printf("Node deleted successfully!\n");
                }
                break;
            case 3:
                printf("AVL tree (inorder traversal): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("AVL tree (preorder traversal): ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("AVL tree (postorder traversal): ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}
