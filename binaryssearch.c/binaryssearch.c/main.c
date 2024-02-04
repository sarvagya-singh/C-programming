//
//  main.c
//  binaryssearch.c
//
//  Created by Sarvagya Singh on 24/11/23.
//

#include <stdio.h>
#include<stdlib.h>
/*
 typedef struct node{
 int val;
 struct node* right;
 struct node* left;
 }node;
 
 typedef struct node Node;
 
 typedef struct {
 Node * nodes[100];
 int tos;
 }Stack;
 
 void push(Stack * s,Node * x){
 s->nodes[++(s->tos)] = x;
 }
 
 Node * pop(Stack * s){
 return (s->nodes[(s->tos)--]);
 }
 
 Node* peek(Stack * s){
 return (s->nodes[s->tos]);
 }
 
 Node* createnode(int x){
 Node* new = (Node*)malloc(sizeof(Node));
 new->val = x;
 new->right = NULL;
 new->left = NULL;
 return new;
 }
 
 void inOrder(Node * tree){
 if (tree!= NULL){
 inOrder(tree->left);
 printf("%d ",tree->val);
 inOrder(tree->right);
 }
 }
 
 void preOrder(Node* tree){
 if (tree!= NULL){
 printf("%d ",tree->val);
 preOrder(tree->left);
 preOrder(tree->right);
 }
 }
 
 void postOrder(Node* tree){
 if (tree!= NULL){
 postOrder(tree->left);
 postOrder(tree->right);
 printf("%d ",tree->val);
 }
 }
 
 void insertBST(Node** tree, int x){
 Node * iter = (Node*)malloc(sizeof(Node));
 Node * prev = (Node*)malloc(sizeof(Node));
 Node * root = (Node*)malloc(sizeof(Node));
 Node * temp = (Node*)malloc(sizeof(Node));
 
 temp = createnode(x);
 prev = NULL;
 root = *tree;
 iter = root;
 
 while (iter != NULL){
 prev = iter;
 if (iter->val > x)
 iter = iter->left;
 else
 iter = iter->right;
 }
 if (prev == NULL)
 *tree = temp;
 else if (x < prev->val)
 prev->left = temp;
 else
 prev->right = temp;
 }
 
 int main(){
 int n,i,x;
 Node* tree = (Node*)malloc(sizeof(Node));
 tree = NULL;
 
 printf("Enter number of elements \n");
 scanf("%d",&n);
 for(i=0;i<n;i++){
 printf("Enter element: ");
 scanf("%d",&x);
 insertBST(&tree,x);
 }
 printf("Inorder traversal: ");
 inOrder(tree);
 }
 */

//BINARY SEARCH TREE FIRST ATTEMPT
typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}node;

typedef struct node Node;

typedef struct{
    Node* nodes[100];
    int tos;
}Stack;

void push(Stack* s,Node* n){
    s->nodes[++(s->tos)] = n;
}

Node* pop(Stack*s){
    return (s->nodes[(s->tos)--]);
}

Node * peek(Stack* s){
    return (s->nodes[(s->tos)]);
}

Node * createNode(int x){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void inOrder(Node* tree){
    while (tree != NULL){
        inOrder(tree->left);
        printf("%d",tree->val);
        inOrder(tree->right);
    }
}
void preOrder(Node* tree){
    if (tree!= NULL){
    printf("%d ",tree->val);
    preOrder(tree->left);
    preOrder(tree->right);
    }
}
void postOrder(Node* tree){
    if (tree!= NULL){
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d ",tree->val);
    }
}

//*********CREATING BINARY TREE FUNCTION**********
void insertBST(Node** tree,int x){
    Node* iter = (Node*)malloc(sizeof(Node));
    Node* prev = (Node*)malloc(sizeof(Node));
    Node* root = (Node*)malloc(sizeof(Node));
    Node* temp = (Node*)malloc(sizeof(Node));
    
    temp = createNode(x);
    prev = NULL;
    root = *tree;
    iter = root;
    
    while (iter != NULL){
        prev = iter;
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    
    if (prev == NULL){
        *tree = temp;
    }
    else if (x < prev->val)
        prev->left = temp;
    else
        prev->right = temp;
}

//********DELETE AND REPLACE FUNCTION ********
void delAndReplace(Node** tree,int x){
    Node* iter = (Node*)malloc(sizeof(Node));
    Node* iter2 = (Node*)malloc(sizeof(Node));
    Node* root = (Node*)malloc(sizeof(Node));
    
    root = *tree;
    iter = root;
    
    while (iter->val != x){
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if ((iter->left != NULL) && (iter->right != NULL)){
        iter2 = iter->left;
        while(iter2->right != NULL)
            iter2 = iter2->right;
        iter->val = iter2->val;
    }
}
//**********FINDING ANCESTORS FUNCTION**********
int findAncestors(Node* tree,int x){
    if (tree == NULL)
        return 0;
    if (tree->val == x)
        return 1;
    if (findAncestors(tree->left,x) || findAncestors(tree->right,x)){
        printf("%d ",tree->val);
        return 1;
    }
    return 0;
}

//******FINDING IN-ORDER SUCCESSOR OF NODE*********
int findSuccessor(Node** tree, int x){
    Stack nodestack;
    nodestack.tos = -1;
    Node* iter = (Node*)malloc(sizeof(Node));
    Node* succ = (Node*)malloc(sizeof(Node));
    iter = *tree;
    push(&nodestack,iter);
    
    while (iter != NULL){
        if (iter->val > x){
            succ = iter;
            iter = iter->left;
        }
        else if(iter->val < x){
            iter = iter->right;
        }
        else{
            if (iter->right != NULL){
                succ = iter->right;
                while (iter->left !=NULL){
                    succ = succ->left;
                }
            }
            break;
        }
    }
    if (succ == NULL){
        return -1;
    }else {
        return succ->val;
    }
}

int main(){
    int n,i,x;
    Node* tree = (Node*)malloc(sizeof(Node));
    tree = NULL;
    
    printf("Enter Number of Elements");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter Element:");
        scanf("%d",&x);
        insertBST(&tree,x);
    }
    printf("Tree Inorder:");
    inOrder(tree);
    printf("Enter element to find ancestors of:");
    scanf("%d",&x);
    printf("Enter element to delete");
    scanf("%d",&x);
    delAndReplace(&tree,x);
}
