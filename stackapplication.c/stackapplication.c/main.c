//
//  main.c
//  stackapplication.c
//
//  Created by Sarvagya Singh on 04/12/23.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct{
    int st[20];
    int tos;
}Stack;

void push(Stack * s, int ch){
    (s->st)[++(s->tos)] = ch;
}

int pop(Stack * s){
    return (s->st)[(s->tos)--];
}

int isOp( char ch){
    switch (ch){
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default: return 0;
    }
}

//EVALUATIONG PREFIX EXPRESSION
/*
int operate (int op1,int op2, char operator){
    switch (operator){
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        default: return 0;
    }
}

int main(){
    int i, temp;
    char expr[100];
    printf("Enter the prefix expression: ");
    scanf("%s",expr);
    Stack s;
    s.tos = -1;
    
    int op1,op2;
    
    i = strlen(expr) - 1;
    
    do {
        if (isOp(expr[i])){
            op1 = pop(&s);
            op2 = pop(&s);
            temp = operate(op1,op2,expr[i]);
            push (&s,temp);
        }
        
        else {
            temp = expr[i] - '0';
            push(&s,temp);
        }
        i--;
    }while (expr[i] != '\0');
    
    printf("Final Answer: %d ", s.st[0]);
}
*/

//INFIX TO PREFIX

char viewTop(Stack* s){
    return (s->st[s->tos]);
}

int getPrec(char ch){
    switch (ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

int main(){
    int i , ind = 0;
    char ch, expr[20],pref[20],ans[20];
    printf("Enter Expression:");
    scanf("%s",expr);
    Stack s;
    s.tos = -1;
    
    int p1 = 0, p2 = 0;
    
    i = strlen(expr)-1;
    
    do{
        if (expr[i] == ')'){
            push (&s, ')');
        }
        else if (expr[i] == '('){
            while (viewTop (&s) != ')'){
                ans[ind++] = pop(&s);
            }
            ch = pop(&s);
        }
        else if (isOp(expr[i])){
            do {
                if(s.tos != -1){
                    p1 = getPrec(viewTop(&s));
                    p2 = getPrec(expr[i]);
                    if (p1>=p2){
                        ans[ind++] = pop(&s);
                    }
                }
            }while (p1>p2);
            push(&s,expr[i]);
        }
        else {
            ans[ind++] = expr[i];
        }
        i--;
    }while (expr[i] != '\0');
    
    while (s.tos >= 0)
        ans[ind++] = s.st[s.tos--];
    
    ans[ind] = '\0';
    int len = (int)strlen(ans);
    printf("Prefix Expression is: ");
    for (i = len-1; i>=0; i--){
        printf("%c",ans[i]);
    }
}

