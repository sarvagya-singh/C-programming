//
//  main.c
//  binarytree.c
//
//  Created by Sarvagya Singh on 24/11/23.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//BINARY TREE ATTEMPT 1

typedef struct node{
    int val;
    struct node* right;
    struct node* left;
}node;

typedef struct node Node;

typedef struct {
    Node* nodes[100];
    int tos;
}Stack;

void push (Stack* s,Node* n){
    s->nodes[++(s->tos)] = n;
}

Node* pop(Stack* s){
    return s->nodes[(s->tos)--];
}

Node* createnode(int x){
    Node* new =(Node*)malloc(sizeof(Node));
    new->val = x;
    new->right = NULL;
    new->left = NULL;
    return new;
}

void inOrder(Node* tree){
    if(tree != NULL){
        inOrder(tree->left);
        printf("%d",tree->val);
        inOrder(tree->right);
    }
}
void preOrder(Node* tree){
    if(tree != NULL){
        printf("%d",tree->val);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
void postOrder(Node* tree){
    if(tree != NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d",tree->val);
    }
}

void createBT(Node** tree){
    Node* iter = (Node*)malloc(sizeof(Node));
    Node* root = (Node*)malloc(sizeof(Node));
    Stack nodestack;
    nodestack.tos = -1;
    iter = NULL;
    int x,inp = 0;
    printf("Enter root value: \n");
    scanf("%d",&x);
    iter = createnode(x);
    push(&nodestack,iter);
    root = iter;
    *tree = iter;
    
    printf("1.Enter Left\n2.Enter Right\n.3.Move Up\n-1.Exit");
    
    do{
        printf("Enter Choice: ");
        scanf("%d",&inp);
        if(inp == 1){
            printf("Enter value to insert: ");
            scanf("%d",&x);
            Node* temp = createnode(x);
            push(&nodestack,iter);
            iter->left = temp;
            iter = iter->left;
            printf("Moved Left!");
        }
        else if(inp == 2){
            printf("Enter value to insert: ");
            scanf("%d",&x);
            Node* temp = createnode(x);
            push(&nodestack,iter);
            iter->right = temp;
            iter = iter->right;
            printf("Moved Right!");
        }
        else if (inp == 3){
            if (nodestack.tos == 0)
                printf("Already at root ab kya tera ma ko chode?");
            else {
                iter = pop(&nodestack);
                printf("Moved Up");
            }
        }
        else
            inp = -1;
        
    }while(inp != -1);
}
//*********COPYING TREES************
Node* copy (Node* node){
    if (node == NULL)
        return NULL;
    Node* new = createnode(node->val);
    new->left = copy(node->left);
    new->right = copy(node->right);
    
    return new;
}

//**********CHECKING FOR EQUALITY***********
int eqCheck(Node * node1, Node* node2){
    if (node1 == NULL && node2 == NULL)
        return 1;
    if (node1 == NULL || node2 == NULL)
        return 0;
    if(node1->val != node2->val)
        return 0;
    return eqCheck(node1->left,node2->left)&& eqCheck(node1->right,node2->right);
}


//*********ITERATIVE PRE ORDER*************
void iterPreOrder(Node** tree){
    Node * temp = (Node *) malloc(sizeof(Node));
    Stack s;
    s.tos = -1;
    push (&s,*tree);
    while (s.tos != -1){
        printf("%d",temp->val);
        if (temp->right != NULL)
            push (&s,temp->right);
        if (temp->left != NULL)
            push (&s,temp->left);
    }
}

void iterInOrder (Node** tree){
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do{
        if (temp != NULL){
            push (&s,temp);
            temp = temp->left;
        }
        else{
            if (s.tos != -1){
                temp = pop(&s);
                printf("%d",temp->val);
                temp = temp->right;
            }
            else
                break;
        }
    }while (1);
}

//*******EXPRESSION TREE FOR POSTFIX EXPRESSION********
double eval(char op,double x,double y) {
    if (op == '+')  return x+y;
    if (op == '-')  return x-y;
    if (op == '*')  return x*y;
    if (op == '/')  return x/y;
    return 0;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

double evaluate(Node * node){
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return (double)(node->val - '0');
    
    double x = evaluate(node->left);
    double y = evaluate(node->right);
    
    return eval(node->val,x,y);
}

int main(){
    Node* tree = (Node*)malloc(sizeof(Node));
    createBT(&tree);
    printf("\nInorder ");
    inOrder(tree);
    printf("\nPreorder ");
    preOrder(tree);
    printf("\nPostorder ");
    postOrder(tree);
    
    //COPY TREE
    Node* treecopy = (Node*)malloc(sizeof(Node));
    treecopy = copy(tree);
    printf("\nInorder of copy: ");
    inOrder(treecopy);
    
    //EQUALITY CHECK
    int check = eqCheck(tree,treecopy);
    if (check)
        printf("Equal");
    else
        printf("Not Equal");
    
    
    //POSTFIX EVAL
    /*char postfix[100];
    int i;
    Stack nodestack;
    nodestack.tos = -1;
    printf("Enter postfix expression : ");
    scanf("%s",postfix);
    for (i=0;i<strlen(postfix);i++) {
            if (!isOperator(postfix[i]))
                push(&nodestack,createnode(postfix[i]));
            else {
                Node * root = createnode(postfix[i]);
                root->right = pop(&nodestack);
                root->left = pop(&nodestack);
                push(&nodestack,root);
            }
        }

        Node * root = pop(&nodestack);
        printf("Ans :  %lf",evaluate(root));
     */
}
