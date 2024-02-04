//
//  main.c
//  circular_linkedlist.c
//
//  Created by Sarvagya Singh on 25/09/23.
//

#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void list_traversal(struct node* head){
    struct node* ptr = head;
    printf("Element is: %d\n",ptr->data);
    ptr = ptr->next;
    while (ptr != head){
        printf("element: %d\n",ptr ->data);
        ptr = ptr ->next;
    }
}
struct node * insertatFirst(struct node* head, int data){
    struct node* ptr =(struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head->next;
    while (p->next != head){
        p = p->next;
    }
    //At this point p points to the last node of the Cir linked list
    p->next = ptr;
    p->next = head;
    head = ptr;
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
    third -> next = head;
    
    printf("Linked list before insertion\n");
    list_traversal(head);
    printf("Linked list after insertion\n");
    head = insertatFirst(head,99);
    list_traversal(head);
    
    
}
