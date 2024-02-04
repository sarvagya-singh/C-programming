//
//  main.c
//  stack_operations.c
//
//  Created by Sarvagya Singh on 14/09/23.
//

#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef struct{
    int arr[MAX_SIZE];
    int top;
}stack;

int isEmpty(stack s){
    return s.top == -1;
}

int isFull(stack s){
    return s.top == MAX_SIZE -1;
}

void push(stack* s,int n){
    if (isFull(*s))
        printf("stack overflow");
    else
        s->arr[++(s->top)] = n;
}

int pop(stack* s){
    if (isEmpty(*s)){
        printf("stack empty");
        return 1;
    }
    return s->arr[s->top--];
}

void display(stack s){
    printf("[ ");
       for (int i = 0; i <= s.top; i++)
           printf("%c ", s.arr[i]);
       printf("]\n");
}

int main(){
    int input = 0;
        stack *s;
        s = malloc(sizeof(stack));

        if (s == NULL)
        {
            printf("Memory allocation failed. Exiting.\n");
            return 1;
        }

        s->top = -1; // Initialize the tos member

        while (input != 3)
        {
            printf("Do you want to push, pop, or exit? (1/2/3) ");
            scanf(" %d", &input);
            char out;
            switch (input)
            {
            case 1:
                printf("Enter the character to push: ");
                char in;
                scanf(" %c", &in);
                push(s, in);
                display(*s);
                break;
            case 2:
                out = pop(s);
                printf("Popped %c\n", out);
                display(*s);
                break;

            case 3:
                printf("Bye Bye\n");
                break;
            default:
                break;
            }
        }
        
}
