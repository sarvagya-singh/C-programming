//
//  main.c
//  infixtoPostfix.c
//
//  Created by Sarvagya Singh on 25/09/23.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[20];
} String;

typedef struct {
    String* q;
    int front, rear;
    int maxSize;
} Queue;

void enqueue(Queue* q, String s) {
    if (q->rear == q->maxSize - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->rear == -1)
        q->front = 0;
    strcpy((q->q[++(q->rear)]).str, s.str);
}

void prioEnqueue(Queue* q, String s) {
    if (q->rear == q->maxSize - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    for (int i = q->rear; i >= q->front; i--)
        q->q[i + 1] = q->q[i];
    q->rear++;
    strcpy((q->q[q->front]).str, s.str);
}

String dequeue(Queue* q) {
    String s;
    strcpy(s.str, (q->q[0]).str);
    int i;
    for (i = 1; i <= q->rear; i++)
        q->q[i - 1] = q->q[i];
    q->rear--;
    return s;
}

int main() {
    int inp, n;
    String t;
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("Enter max size of queue: ");
    scanf("%d", &n);
    q.maxSize = n;
    q.q = (String*)malloc(n * sizeof(String));
    printf("1. Enqueue, 2. Priority Enqueue, 3. Dequeue, 4. Exit\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &inp);

        if (inp == 1) {
            printf("Enter word to enqueue: ");
            scanf("%s", t.str);
            enqueue(&q, t);
        } else if (inp == 2) {
            printf("Enter word to priority enqueue: ");
            scanf("%s", t.str);
            prioEnqueue(&q, t);
        } else if (inp == 3) {
            if (q.front == -1) {
                printf("Queue is empty. Cannot dequeue.\n");
            } else {
                printf("Word dequeued is: %s\n", dequeue(&q).str);
            }
        } else {
            inp = 4;
        }
    } while (inp != 4);

    free(q.q);

    return 0;
}


 

//INFIX TO POSTFIX USING STACK
/*struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2;
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/')
        return 1;
    else
        return 0;
}
char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
*/

//MALLOC CALLOC REALLOC
/*
 int main(){
    int n,i,k;
    int* ptr;
    printf("Enter the size of your array:");
    scanf("%d",&n);
    ptr =(int*)calloc(n,sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }
    printf("Array:\n");
    for(i=0;i<n;i++){
        printf("%d ",ptr[i]);
    }
    printf("enter size of new array:");
    scanf("%d",&k);
    ptr = (int*)realloc(ptr,k*sizeof(int));
    printf("Array:\n");
    for(i=0;i<k;i++){
        printf("%d ",ptr[i]);
    }
    free(ptr);
}


void tower(int n, char beg,char aux,char end){
    if (n==0)
    printf("illeagal entry");
    else if (n==1)
        printf("Move disc from %c to %c\n",beg,end);
    else{
        tower(n-1,beg,end,aux);
        tower(1,beg,aux,end);
        tower(n-1,aux,beg,end);
    }
}

int main(){
    int n;
    char a, b, c;
    printf("Enter number of discs\n");
    scanf("%d",&n);
    printf("Tower of hanoi of %d discs are:\n",n);
    tower(n,'a','b','c');
}
*/
