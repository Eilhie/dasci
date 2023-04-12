#include <stdio.h>
#include <stdlib.h>

// // define the structure of a binary search tree node
// struct node {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// // function to create a new node with the given data
// struct node* newNode(int data) {
//     struct node* node = (struct node*)malloc(sizeof(struct node));
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }

// // function to insert a new node with the given data into the BST
// struct node* insert(struct node* node, int data) {
//     // if the BST is empty, return a new node
//     if (node == NULL)
//         return newNode(data);

//     // otherwise, recur down the tree
//     if (data < node->data)
//         node->left = insert(node->left, data);
//     else if (data > node->data)
//         node->right = insert(node->right, data);

//     // return the (unchanged) node pointer
//     return node;
// }

// // function to find the inorder successor (smallest in the right subtree)
// struct node* minValueNode(struct node* node) {
//     struct node* current = node;

//     /* loop down to find the leftmost leaf */
//     while (current && current->left != NULL)
//         current = current->left;

//     return current;
// }

// // function to delete a node with the given key from the BST
// struct node* deleteNode(struct node* root, int key) {
//     // base case: if the tree is empty, return null
//     if (root == NULL)
//         return root;

//     // if the key to be deleted is smaller than the root's key,
//     // then it lies in the left subtree
//     if (key < root->data)
//         root->left = deleteNode(root->left, key);

//     // if the key to be deleted is greater than the root's key,
//     // then it lies in the right subtree
//     else if (key > root->data)
//         root->right = deleteNode(root->right, key);

//     // if key is same as root's key, then this is the node to be deleted
//     else {
//         // node with only one child or no child
//         if (root->left == NULL) {
//             struct node* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL) {
//             struct node* temp = root->left;
//             free(root);
//             return temp;
//         }

//         // node with two children: get the inorder successor (smallest in the right subtree)
//         struct node* temp = minValueNode(root->right);

//         // copy the inorder successor's content to this node
//         root->data = temp->data;

//         // delete the inorder successor
//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }

// // inorder traversal of binary tree
// void inorderTraversal(node* node) {
//     if (node == NULL)
//         return;

//     inorderTraversal(node->left);
//     printf("%d ", node->data);
//     inorderTraversal(node->right);
// }

// // preorder traversal of binary tree
// void preorderTraversal(node* node) {
//     if (node == NULL)
//         return;

//     printf("%d ", node->data);
//     preorderTraversal(node->left);
//     preorderTraversal(node->right);
// }

// // postorder traversal of binary tree
// void postorderTraversal(node* node) {
//     if (node == NULL)
//         return;

//     postorderTraversal(node->left);
//     postorderTraversal(node->right);
//     printf("%d ", node->data);
// }

// // function to search for a value in a binary search tree
// struct node* search(struct node* root, int data) {
//     if (root == NULL || root->data == data)
//         return root;

//     if (root->data < data)
//         return search(root->right, data);

//     return search(root->left, data);
// }

// // function to count the height of a binary search tree
// int height(struct node* root) {
//     if (root == NULL)
//         return -1;

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);

//     if (leftHeight > rightHeight)
//         return leftHeight + 1;
//     else
//         return rightHeight + 1;
// }


// int main() {
//     struct node* root = NULL;

//     // insert some nodes into the BST
//     root = insert(root, 8);
//     root = insert(root, 3);
//     root = insert(root, 10);
//     root = insert(root, 1);
//     root = insert(root, 6);
//     root = insert(root, 14);
//     root = insert(root, 4);
//     root = insert(root, 7);
//     root = insert(root, 13);

//     printf("Inorder traversal of the BST: ");
//     inorderTraversal(root);
//     puts("");
//     deleteNode(root,10);

//     // perform an inorder traversal of the BST
//     printf("Inorder traversal of the BST: ");
//     inorderTraversal(root);
//     printf("\n");

//     return 0;
// }



struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value){
    if(root == NULL) return createNode(value);
    if(root->value < value) root->right = insert(root->right, value);
    else root->left = insert(root->left, value);

    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

Node* search(Node* root, int key){
    if(root == NULL) return root;
    if(root->value == key) return root;
    else if(root->value > key) return search(root->left, key);
    else return search(root->right, key);
}

int height(Node* root){
    if(root == NULL) return -1;
    int left = height(root->left);
    int right = height(root->right);
    if(left > right) return left + 1;
    else return right + 1;
}

Node* minValueNode(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL) curr = curr->left;

    return curr;
}

Node* remove(Node* root, int key){
    if(root == NULL) return root;

    if(key < root->value) root->left = remove(root->left, key);
    else if(key > root->value) root->right = remove(root->right, key);
    else {
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right); // right most left 
        root->value = temp->value;
        root->right = remove(root->right, temp->value);
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    // insert some nodes into the BST
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    printf("preorder traversal of the BST: ");
    preorder(root); puts("");

    remove(root, 3);

    printf("preorder traversal of the BST: ");
    preorder(root); puts("");

    printf("postorder traversal of the BST: ");
    postorder(root); puts("");
    printf("inorder traversal of the BST: ");
    inorder(root); puts("");

    Node* found = search(root, 1);
    if(found == NULL) puts("NOT FOUND");
    else printf("%d found\n", found->value);

    printf("height : %d\n", height(root));
    return 0;
}