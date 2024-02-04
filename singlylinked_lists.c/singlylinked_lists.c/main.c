//
//  main.c
//  singlylinked_lists.c
//
//  Created by Sarvagya Singh on 25/09/23.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//LIST FUNCTIONS

typedef struct node{
    int val;
    struct node * next;
}node;

typedef struct node Node;

void insertnode(Node* prev, int x){
    Node * new = (Node*)malloc(sizeof(Node));
    new->val = x;
    new->next = prev->next;
    prev->next = new;
}

void display(Node* node){
    while(node != NULL){
        printf("%d",node->val);
        node = node->next;
    }
    printf("\n");
}

void input (Node * node, int n){
    int i, temp;
    for (i=0;i<n;i++){
        printf("Enter value to add");
        scanf("%d",&temp);
        if(i==0){
            node->val = temp;
            node-> next = NULL;
            continue;
        }
        insertnode(node,temp);
        node = node->next;
    }
}

void deletenode(Node** list,Node* tbd){
    if (*list == tbd){
        *list = (*list)->next;
    }
    else{
        Node * temp = (Node*)malloc(sizeof(Node));
        temp = *list;
        while( temp->next != NULL){
            if(temp->next == tbd){
                temp->next = tbd->next;
            }
            temp = temp->next;
        }
    }
    free(tbd);
}
//*********UNION AND INTERSECTION**********
int search(Node* list,int x){
    while (list != NULL){
        if (list->val == x)
            return 1;
        list = list->next;
    }
    return 0;
}
void getUnion(Node* list1,Node* list2, Node* un){
    int i = 0;
    Node * unHead = (Node*)malloc(sizeof(node));
    unHead = un;
    while (list1 != NULL){
        if (i==0){
            i=1;
            un->val = list1->val;
            un->next = NULL;
        }
        else {
            if (search(unHead,list1->val)== 0){
                insertnode(un,list1->val);
                un = un->next;
            }
        }
        list1 = list1->next;
    }
    while (list2 != NULL){
        if (search(un,list2->val)== 0){
            insertnode(un,list2->val);
            un = un->next;
        }
        list2 = list2->next;
    }
}

void intersection(Node* list1,Node* list2, Node* inter){
    int i = 0;
    //list1 is the smaller list
    while(list1 != NULL){
        if (search(list2,list1->val)){
            if (i==0){
                i=1;
                inter->val = list1->val;
                inter->next = NULL;
            }
            else {
                insertnode(inter,list1->val);
                inter = inter->next;
            }
        }
        list1 = list1->next;
    }
}
//IMPLEMENTING A QUEUE
int isempty(Node * list){
    if (list == NULL)
        return 1;
    return 0;
}

void enqueue(Node ** list, int x){
    Node * new = (Node*)malloc(sizeof(node));
    if(isempty(*list)){
        *list = new;
        (*list)->val = x;
        (*list)->next = NULL;
    }
    else{
        new = *list;
        while(new->next !=NULL)
            new = new->next;
        insertnode(new,x);
    }
}

int dequeue(Node ** list){
    if (isempty(*list)){
        printf("Error,empty lawda");
        return -5;
    }
    else {
        int x = (*list)->val;
        deletenode(list,*list);
        return x;
    }
}

int main(){
    int x,inp;
    Node* list = (Node*)malloc(sizeof(Node));
    list = NULL;
    printf("1.Enqueue \n2.Dequeue \n3.Display \n-1.Exit");
    do{
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1){
            printf("Enter number to enqueue ");
            scanf("%d",&x);
            enqueue(&list,x);
        }
        else if(inp == 2){
            printf("Dequeued: %d", dequeue(&list));
        }
        else if (inp == 3){
            display(list);
        }
        else
            inp = -1;
    }while (inp!=-1);
    
    int n1,n2;
        printf("Enter number of elements in list 1: ");
        scanf("%d",&n1);
        printf("Enter number of elements in list 2: ");
        scanf("%d",&n2);
        Node * list1 = (Node *) malloc(sizeof(Node));
        Node * list2 = (Node *) malloc(sizeof(Node));
        Node * intersectionList = (Node *) malloc(sizeof(Node));
        Node * unionList = (Node *) malloc(sizeof(Node));

        printf("Enter elements for list1:\n");
        input(list1,n1);
        printf("The list is: ");
        display(list1);
        printf("Enter elements for list2:\n");
        input(list2,n2);
        printf("The list is: ");
        display(list2);
        printf("Union is: ");
        getUnion(list1,list2,unionList);
        display(unionList);
        printf("Intersection is: ");
        if (n1 <= n2)
            intersection(list1,list2,intersectionList);
        else
            intersection(list2,list1,intersectionList);
        display(intersectionList);
}

 
/*
//POLYNOMIAL ADDITION
typedef struct node{
    int coeff;
    int exp;
    struct node* next;
}node;

typedef struct node Node;

void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coeff = coef;
    temp->exp = exp;
    temp->next = NULL;
    
    if (*poly == NULL) {
        *poly = temp;
        return;
    }
    
    Node* current = *poly;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = temp;
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    Node* current = poly;
    
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    
    printf("\n");
}

Node* add (Node* poly1, Node* poly2){
    Node* result = NULL;
    
    while( poly1 != NULL && poly2 != NULL){
        if (poly1->exp == poly2->exp){
            insert(&result,poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }else if (poly1->exp > poly2->exp){
            insert (&result,poly1->coeff,poly1->exp);
            poly1 = poly1->next;
        }else{
            insert (&result,poly2->coeff,poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL){
        insert (&result,poly1->coeff,poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL){
        insert (&result,poly2->coeff,poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
}

int main() {
    Node* poly1 = NULL;
    insert(&poly1, 5, 4);
    insert(&poly1, 3, 2);
    insert(&poly1, 1, 0);
    Node* poly2 = NULL;
    insert(&poly2, 4, 4);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);
    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);
    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);
    return 0;
}















































/*#include <stdio.h>
 #include<stdlib.h>
 
 struct node{
 int data;
 struct node *next;
 };
 
 void list_traversal(struct node* ptr){
 while (ptr != NULL){
 printf("element: %d\n",ptr ->data);
 ptr = ptr ->next;
 }
 }
 
 struct node * insertatFirst(struct node* head, int data){
 struct node* ptr =(struct node *)malloc(sizeof(struct node));
 ptr -> next = head;
 ptr -> data = data;
 return ptr;
 }
 struct node * insertatEnd(struct node* head, int data){
 struct node* ptr =(struct node *)malloc(sizeof(struct node));
 ptr -> data = data;
 struct node* p = head;
 
 while (p->next != NULL){
 p = p->next;
 }
 p->next = ptr;
 ptr->next = NULL;
 return head;
 }
 struct node* insertatIndex(struct node* head, int data,int index){
 struct node* ptr =(struct node *)malloc(sizeof(struct node));
 struct node* p = head;
 int i = 0;
 
 while (i!= index-1){
 p = p ->next;
 i++;
 }
 ptr -> data = data;
 ptr ->next = p ->next;
 p ->next = ptr;
 return head;
 }
 
 int main(){
 struct node* head;
 struct node* second;
 struct node* third;
 
 head = (struct node*)malloc(sizeof(struct node));
 second = (struct node*)malloc(sizeof(struct node));
 third = (struct node*)malloc(sizeof(struct node));
 
 head -> data = 23;
 head -> next = second;
 
 second -> data = 52;
 second -> next = third;
 
 third -> data = 33;
 third -> next = NULL;
 
 printf("Linked list before insertion\n");
 list_traversal(head);
 //head = insertatFirst(head,56);
 //head = insertatIndex(head,44,1);
 head = insertatEnd(head,99);
 printf("Linked list after insertion\n");
 list_traversal(head);
 }
 */
