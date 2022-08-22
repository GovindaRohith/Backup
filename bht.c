#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int min(int *arr)
{
    if(arr!=NULL) return arr[0];
    else return -1;
}
//      parent
//         i
//   c1           c2
//    2*i          2*i+1 
int * swap(int *arr,int i1,int i2)
{
    int temp=arr[i1];
    arr[i1]=arr[i2];
    arr[i2]=temp;
    return arr;
}
int * insert(int *arr,int n)
{
    
    return arr;
}
int * delete(int *arr,int n)
{
    return arr;
}
int main()
{
    int *arr;
    arr=(int *)malloc(sizeof(int)*SIZE);
    free(arr);
    return 0;
}