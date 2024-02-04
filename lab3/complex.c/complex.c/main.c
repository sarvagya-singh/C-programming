//
//  main.c
//  complex.c
//
//  Created by Sarvagya Singh on 24/08/23.
//

#include <stdio.h>
#include<stdlib.h>

typedef struct complex{
    int real;
    int img;
}complex;

complex add(complex n1, complex n2);
complex multiply(complex n1,complex n2);
complex subs(complex n1, complex n2);

int main(){
    complex n1,n2, sum,mult,bhed;
    
    printf("For first complex number: \n");
    printf("Enter real and imaginary parts: \n");
    scanf("%d%d",&n1.real,&n1.img);
    printf("For second complex number: \n");
    printf("Enter real and imaginary parts: \n");
    scanf("%d%d",&n2.real,&n2.img);
    
    sum = add(n1,n2);
    printf("Sum = %d + i%d\n", sum.real,sum.img);
    mult = multiply(n1,n2);
    printf("Product = %d + i%d\n", mult.real,mult.img);
    bhed = subs(n1,n2);
    printf("Substraction = %d + i%d \n", bhed.real,bhed.img);
    return 0;
}
complex add(complex n1, complex n2){
    complex temp;
    temp.real = n1.real + n2.real;
    temp.img = n1.img + n2.img;
    return (temp);
}
complex multiply(complex n1,complex n2){
    complex m;
    m.real = n1.real*n2.real;
    m.img = n1.img*n2.img;
    return (m);
}
complex subs(complex n1, complex n2){
    complex s;
    s.real = n1.real - n2.real;
    s.img = n1.img - n2.img;
    return (s);
}
