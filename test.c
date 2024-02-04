//
//  test.c
//  smallarr.c
//
//  Created by Sarvagya Singh on 18/08/23.
//

#include <stdio.h>
//reversing array
int main()
{
    int a[10],i,n;
    printf("enter size of array");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        }
    for (i=n-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
