#include<stdio.h>
#include<stdlib.h>
int * ins(int *arr,int k)
{
    return arr;
}
int * del(int *arr,int k)
{
    // for()
    return arr;
}
int main()
{
    int *arr,n,i;
    printf("Enter number of elements  ");
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int )*(n+2));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //n     n+1
    int k;
    printf("Enter element to delete ");
    scanf("%d",&k);
    arr=del(arr,k);
    for(i=0;i<n-1;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("%d\n",arr[n-1]);
    free(arr);
    return 0;
}