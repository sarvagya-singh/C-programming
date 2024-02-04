//
//  main.c
//  circular_queue.c
//
//  Created by Sarvagya Singh on 25/09/23.
//

#include <stdio.h>
#include<stdlib.h>
/*
struct cirqueue{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct cirqueue *q){
    if (q->r == q->size-1)
        return 1;
    return 0;
}

void enqueue(struct cirqueue *q, int val){
    if ((q->r+1)% q->size == q->f){
        printf("Queeu Full");
    }
    else {
        q->r = (q->r+1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue (struct cirqueue *q){
    int a = -1;
    if (q->f == q->r){
        printf("Queue Empty");
    }
    else {
        q->f = (q->f+1)% q->size;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct cirqueue*q){
    int i;
    if (q->f && q->r ==-1)
        printf("Queue is mepty");
    else{
        for(i= q->f; i<q->r+1;i++){
            printf("%d\n",q->arr[i]);
        }
    }
    
}
int main(){
    struct cirqueue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size* sizeof(int));
    
    enqueue(&q,38);
    enqueue(&q,44);
    enqueue(&q,99);
    display(&q);
    return 0;
}
*/


//STACK IMPLEMENTATION USING LINKED LIST

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* current = NULL;

//STACK KE LIYE
//INSERTION AT BEGINING AND DELETION AT BEGINING
void display(){
    struct node* p = head; //FIRST ELEMENT
    printf("\n[");
    
    //START FROM THE BEGINING
    while(p!= NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("]");
}
//INSERTION AT THE BEGINING
void push(int val){
    //create link
    struct node* lk =(struct node*)malloc(sizeof(struct node));
    lk->data = val;
    
    lk->next = head;
    
    head = lk;
    printf("Pushed %d onto the stack:\n",head->data);
}
//DELETION AT THE BEGINING
void pop(){
    int a;
    head = head->next;
    printf("Itm popped: %d\n",head->data);
    a = head->data;
}
//FOR QUEUE DELETE AT
void deleteatEnd(){
    struct node* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
        temp->next = NULL;
    }
}

int main(){
    //struct node* p =(struct node*)malloc(sizeof(struct node));
    push(30);
    push(44);
    push(29);
    push(82);
    push(54);
    pop();
    pop();
    display();
}
