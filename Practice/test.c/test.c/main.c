//
//  main.c
//  test.c
//
//  Created by Sarvagya Singh on 18/08/23.
//
#include <stdio.h>
#include <stdlib.h>
/*void Reverse(int *a,int n)
{
    int i, temp[50];
    for (i=0;i<n;i++){
        temp[i]=a[n-i-1];
    }
    for (i=0;i<n;i++){
        a[i]=temp[i];
    }
}
int main()
{
    int i,n;
    int *a;
    printf("enter size \n");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    printf("entee the elements \n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("the reversed array is: \n");
    Reverse(a,n);
    for (i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
*/
int smallest(int *a, int n){
    int i,sml=a[0];
    for (i=0;i<n;i++){
        if (a[i]<sml)
            sml=a[i];
    }
    return (sml);
}
int main()
{
    int i,n,sml;
    int *a;
    printf ("entrer no of elements:\n");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    printf("enter teh elements\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sml = smallest(a,n);
    printf("the smallest element is %d\n",sml);
    return 0;
}
