#include<stdio.h>
#include<stdlib.h>
int * ins(int *arr,int k,int n)
{
    if(arr[n+1]==n+1)
    {
        printf("Array  full");
        return arr;
    }
    arr[arr[n+1]]=k;
    arr[n+1]++;
    return arr;
}
int * del(int *arr,int n)
{
    if(arr[n+1]==0) 
    {
        printf("Empty array");
        return arr;
    }
    arr[n]=arr[n]+1;
    //n-1 last 
    //n    first
    //index to have first element
    //n+1  end
    //end element index +   1 
    return arr;
}
int * delany(int *arr,int n,int k)
{
    
    return arr;
}
void printer(int *arr,int n)
{
    int i;
    for(i=arr[n];i<arr[n+1];i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int *arr,n,i,k;
    printf("Enter number of elements  ");
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int )*(n+2));
    arr[n]=0;
    arr[n+1]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        arr=ins(arr,k,n);
    }
    arr=del(arr,n);
    printer(arr,n);    
    free(arr);
    return 0;
}