//
//  main.c
//  array_queue.c
//
//  Created by Sarvagya Singh on 25/09/23.
//

#include <stdio.h>
#include<stdlib.h>

/*struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

void enqueue(struct queue* q, int val){
    if (q->r == q->size-1){
        printf("Queue Overflow");
    }
    else{
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue* q){
    if (q->r && q->f){
        printf("Empty Queue");
    }
    else{
        q->f = q->f + 1;
    }
    return q->arr[q->f];
}

void display(struct queue* q){
    int i;
    for(i = q->f; i<q->r+1; i++){
        printf("%d\n",q->arr[i]);
    }
}

int main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    enqueue(&q,90);
    enqueue(&q,34);
    enqueue(&q,55);
    dequeue(&q);
    display(&q);
    
    return 0;
}
*/

/*struct queue{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct queue *q){
    if (q->r == q->size-1)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val){
    if (isFull(q)){
        printf("Queeu Full");
    }
    else {
        q->r = q->r+1;
        q->arr[q->r] = val;
    }
}

int dequeue (struct queue *q){
    int a = -1;
    if (q->f == q->r){
        printf("Queue Empty");
    }
    else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct queue*q){
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
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size* sizeof(int));
    
    enqueue(&q,38);
    enqueue(&q,44);
    enqueue(&q,99);
    display(&q);
    return 0;
}
*/

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* s){
    if(s->top == -1)
        return 1;
    return 0;
}
int isFull(struct stack* s){
    if (s->top == s->size - 1)
        return 1;
    return 0;
}
void push(struct stack* s,int val){
    if (isFull(s))
        printf("Stack Overload");
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}
int pop(struct stack* s){
    int a;
    if (isEmpty(s))
        printf("Stack Underflow");
    else{
        a = s->arr[s->top];
        s->top--;
    }
    return a;
}
void display(struct stack* s){
    int i;
    if (isEmpty(s))
        printf("Stack Underflow");
    for(i=s->top;i<-1;i--){
        printf("%d",s->arr[i]);
    }
    
}
int main(){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->arr = (int*)malloc(s->size*sizeof(int));
    s->top = -1;
    push(s,43);
    push(s,33);
    push(s,59);
    display(s);
    return 0;
}
