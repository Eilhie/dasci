#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int num;
	node *left;
	node *right;
};

node *createnew(int num)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->num = num;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

node *insert(node *root, int num)
{
	if(root == NULL)
	{
		return createnew(num);
	}
	else if(num < root->num)
	{
		root->left = insert(root->left, num);
	}
	else if(num > root->num)
	{
		root->right = insert(root->right, num);
	}
	
	return root;
}

void preorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	printf(" [%d] ", root->num);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	inorder(root->left);
	printf(" [%d] ", root->num);
	inorder(root->right);
}

void postorder(node *root)
{
	if(root == NULL)
	{
		return;
	}

	postorder(root->left);
	postorder(root->right);
	printf(" [%d] ", root->num);
}

node* minimum(node* root)
{
    node *curr = root;
    while(curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}

//node *pop(node *root, int num)
//{
//	if(root == NULL)
//	{
//		printf("No Data\n");
//		return root;
//	}
//	
//	node *par = NULL;
//	node *curr = root;
//	while(curr != NULL && curr->num != num)
//	{
//		par = curr;
//		
//		if(num < curr->num)
//		{
//			curr = curr->left;
//		}
//		else
//		{
//			curr = curr->right;
//		}
//	}
//	
//	if(curr == NULL)
//	{
//		printf("Data [%d] not found\n", num);
//		return root;
//	}
//	
//	if(curr->left == NULL && curr->right == NULL)
//	{
//		if(par = NULL)
//		{
//			free(curr);
//			return NULL;
//		}
//		if(par->left == curr)
//		{
//			par->left = NULL;
//		}
//		else
//		{
//			par->right = NULL;
//		}
//		free(curr);
//		
//		printf("Data [%d] successfully deleted/n", num);
//	}
//	else if(curr->left == NULL || curr->right == NULL)
//	{
//		node *child = (curr->left != NULL) ? curr->left : curr->right;
//		
//		if(par = NULL)
//		{
//			free(curr);
//			return child;
//		}
//		
//		if(par->left == curr)
//		{
//			par->left = child;
//		}
//		else
//		{
//			par->right = child;
//		}
//		free(curr);
//		
//		printf("Data [%d] successfully deleted/n", num);
//	}
//	else
//	{
//		node *temp = minimum(curr->right);
//		curr->num = temp->num;
//		curr->right = pop(curr->right, temp->num);
//		
//		printf("Data [%d] successfully deleted/n", num);
//	}
//	
//	return root;
//}

struct node* pop(struct node* root, int num) 
{
    if (root == NULL) 
	{
        return root;
    }
    
    struct node* parent = NULL;
    struct node* current = root;
    while (current != NULL && current->num != num) 
	{
        parent = current;
        if (num < current->num) 
		{
            current = current->left;
        } 
		else 
		{
            current = current->right;
        }
    }

    if (current == NULL) 
	{
		printf("Data [%d] not found\n", num);
        return root;
    }

    // Case 1: Node has no children
    if (current->left == NULL && current->right == NULL) 
	{
        if (parent == NULL) {
            free(current);
            return NULL;
        }
        if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }
    // Case 2: Node has one child
    else if (current->left == NULL || current->right == NULL) 
	{
        struct node* child = (current->left != NULL) ? current->left : current->right;
        if (parent == NULL) {
            free(current);
            return child;
        }
        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(current);
    }
    // Case 3: Node has two children
    else {
        struct node* successor = minimum(current->right);
        current->num = successor->num;
        current->right = pop(current->right, successor->num);
    }
    return root;
}

int main()
{
	node *root = NULL;
	
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 80);
	root = insert(root, 20);
	root = insert(root, 34);
	root = insert(root, 55);
	
	printf("Preorder Notation:");
	preorder(root);
	puts("");
	
	printf("In-Order Notation:");
	inorder(root);
	puts("");
	
	printf("Postorder Notation:");
	postorder(root);
	puts("");
	
	pop(root, 34);
	pop(root, 80);
	pop(root, 40);
	
	printf("In-Order Notation:");
	inorder(root);
	puts("");
	
	return 0;
}