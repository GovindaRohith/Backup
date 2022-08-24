#include<stdio.h>
#include<stdlib.h>
#define INIT 100
int min(int *arr)
{
    if(arr!=NULL) return arr[1];
    else return -1;
}

void printer(int *arr)
{
    int i;
    for(i=1;i<=arr[0];i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//      parent
//         i
//   c1           c2
//   2*i          2*i+1 
// parent < children
int * insert(int *arr,int n)
{
    // index current size given
    int index=arr[0],temp;
    if(index+1==99) 
    {
        printf("Array full");
        return arr;
    }
    arr[index+1]=n;
    index++;
    while(index>1)
    {
        if(n<arr[index/2]&&index/2>=1)
        {
            temp=arr[index/2];
            arr[index/2]=arr[index];
            arr[index]=temp;
            index=index/2;
        }
        else 
        {
            break;
        }
    }
    arr[0]++;
    return arr;
}
int * delete(int *arr)
{
    int index=1,temp;
    arr[1]=arr[arr[0]];
    while(index<=arr[0]&&(2*index+1)<arr[0])//Equailty verify
    {   
        if(arr[index*2+1]>arr[index*2])
        {
            temp=arr[index];
            arr[index]=arr[index*2];
            arr[index*2]=temp;
            index=index*2;
        }
        else if(arr[index*2]>arr[2*index+1])
        {
            temp=arr[index];
            arr[index]=arr[index*2+1];
            arr[index*2+1]=temp;
            index=index*2+1;
        }
        else
        {       
            break;
        }   
    }
    arr[0]=arr[0]-1;
    return arr;
}
int main()
{
    // arr[0] ==>INIT
    int *arr;
    arr=(int *)malloc(sizeof(int)*INIT);
    arr[0]=0;
    arr=insert(arr,6);
    arr=insert(arr,5);
    arr=insert(arr,2);
    arr=insert(arr,3);
    arr=insert(arr,10);
    arr=insert(arr,1);
    arr=insert(arr,9);
    arr=insert(arr,11);
    arr=insert(arr,7);
    arr=insert(arr,8);
    arr=insert(arr,12);
    printer(arr);
    printf("The minimum value of the BHT is %d \n",min(arr));
    arr=delete(arr);
    printer(arr);
    free(arr);
    return 0;
}