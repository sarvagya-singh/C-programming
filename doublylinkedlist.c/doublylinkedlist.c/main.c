//
//  main.c
//  doublylinkedlist.c
//
//  Created by Sarvagya Singh on 23/11/23.
//

#include <stdio.h>
#include<stdlib.h>
/*
//DOUBLY LIST FUNCTIONS
typedef struct node{
    int val;
    struct node* right;
    struct node* left;
}node;

typedef struct node Node;

void insertnode(Node* prev, int x){
    Node* new = (Node*)malloc(sizeof(Node*));
    new->val = x;
    new->right = prev->right;
    new->left = prev;
    prev->right = new;
}

void insertEnd(Node ** list, int x){
    Node * temp = (Node*)malloc(sizeof(Node));
    Node * new =(Node*)malloc(sizeof(Node));
    temp = *list;
    while (temp->right != NULL)
        temp = temp->right;
    new->val = x;
    new->left = temp;
    temp->right = new;
    new->right = NULL;
}

void insertFront(Node ** list, int x){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->val = x;
    temp->left = NULL;
    if (*list != NULL){
        temp->right = *list;
        (*list)->left = temp;
    }
    *list = temp;
}

void display(Node * node){
    printf("The list is ");
    while (node != NULL){
        printf("%d ",node->val);
        node = node->right;
    }
    printf("\n");
}

void input(Node* node, int n){
    int i,temp;
    for(i=0;i<n;i++){
        printf("Enter the value to add: ");
        scanf("%d",&temp);
        if(i==0){
            node->val = temp;
            node->right = NULL;
            node->left = NULL;
            continue;
        }
        insertnode(node,temp);
        node = node->right;
    }
}

void deletenode(Node ** list, Node * tbd){
    if(*list == tbd){
        *list = (*list)->right;
        (*list)->left = NULL;
    }
    else{
        Node*temp = (Node*)malloc(sizeof(Node));
        temp = *list;
        while(temp->right != NULL){
            if(temp->right == tbd){
                temp->right = tbd->right;
                tbd->left = temp;
                break;
            }
            temp = temp->right;
        }
    }
    printf("\nValue Deleted: %d",tbd->val);
    free(tbd);
}

//MAIN for implementing doubly linked list without header node to insert into and delete from both the sides

int main(){
 int inp,x;
 Node* list = (Node*)malloc(sizeof(Node));
 list = NULL;
 printf("\n1.Insert Front\n2.Insert End\n3.Delete Front\n4.Delete End\n5.Display\n-1.Exit");
 do{
     printf("\nEnter Choice ");
     scanf("%d",&inp);
     
     if(inp == 1){
         printf("Enter element to enter: ");
         scanf("%d",&x);
         insertFront(&list,x);
     }
     else if(inp == 2){
         printf("Enter element to enter: ");
         scanf("%d",&x);
         insertEnd(&list,x);
     }
     else if(inp == 3){
         deletenode(&list,list);
     }
        else if (inp == 4){
            Node * temp =(Node*)malloc(sizeof(Node));
            temp = list;
            while (temp->right != NULL){
                temp = temp->right;
            }
            deletenode(&list,temp);
        }
        else if(inp == 5){
            display(list);
        }
        else
            inp = -1;
    }while(inp!=-1);
}
*/

//DOUBLY LINKED LIST FIRST ATTEMPT
typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}node;

typedef struct node Node;

void insertNode(Node* prev, int x){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = x;
    new->right = prev->right;
    new->left = prev;
    prev->right = new;
}

void insertEnd(Node** list, int x){
    Node * temp = (Node*)malloc(sizeof(Node));
    Node * new =(Node*)malloc(sizeof(Node));
    temp = *list;
    while(temp->right != NULL){
        temp = temp->right;
    }
    new->val = x;
    new->left = temp;
    temp->right = new;
    new->right = NULL;
}

void insertFront(Node** list,int x){
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->val = x;
    if (*list != NULL){
        temp->right = *list;
        (*list)->left = temp;
    }
    *list = temp;
}

void display (Node* node){
    printf("The list is:");
    while (node != NULL){
        printf("%d",node->val);
        node = node->right;
    }
    printf("\n");
}

void input (Node* node,int n){
    
}

void deleteNode(Node** list, Node* tbd){
    if (*list == tbd){
        *list = (*list)->right;
        (*list)->left = NULL;
    }
    else{
        Node*temp = (Node*)malloc(sizeof(Node));
        temp = *list;
        while (temp->right != NULL){
            if (temp->right == tbd){
                temp->right = tbd->right;
                tbd->left = temp;
                break;
            }
            temp = temp->right;
        }
    }
    printf("Valude Deleted: %d",tbd->val);
    free(tbd);
}

int main(){
    int inp,x;
    Node* list = (Node*)malloc(sizeof(Node));
    list = NULL;
    printf("\n1.Insert Front\n2.Insert End\n3.Delete Front\n4.Delete End\n5.Display\n-1.Exit");
    do{
        printf("\nEnter Choice ");
        scanf("%d",&inp);
        
        if(inp == 1){
            printf("Enter element to enter: ");
            scanf("%d",&x);
            insertFront(&list,x);
        }
        else if(inp == 2){
            printf("Enter element to enter: ");
            scanf("%d",&x);
            insertEnd(&list,x);
        }
        else if(inp == 3){
            deleteNode(&list,list);
        }
        else if (inp == 4){
            Node * temp =(Node*)malloc(sizeof(Node));
            temp = list;
            while (temp->right != NULL){
                temp = temp->right;
            }
            deleteNode(&list,temp);
        }
        else if(inp == 5){
            display(list);
        }
        else
            inp = -1;
    }while(inp!=-1);
}

