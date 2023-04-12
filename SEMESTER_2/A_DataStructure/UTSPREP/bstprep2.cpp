#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    Node *left;
    Node *right;
};

Node* createNode(int value){
    Node*  temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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

Node* minValueNode(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL) curr = curr->left;
    return curr;
}

Node* remove(Node* root, int value){
    if(root == NULL) return root;
    if(value < root->value) root->left = remove(root->left, value);
    else if(value > root->value) root->right = remove(root->right, value);
    else {
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = temp;
    }
    return root;
}

Node* search(Node* root, int value){
    if(root == NULL) return root;
    if(root->value == value) return root;
    else if(value < root->value) return search(root->left, value);
    else return search(root->right, value);
}

int height(Node* root){
    if(root == NULL) return -1;
    int left = height(root->left);
    int right = height(root->right);
    if(left > right) return left + 1;
    else return right + 1;
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