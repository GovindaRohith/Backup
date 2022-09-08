// 1.Each node contains the Age of a faculty.
// 2.You should implement take input an array and print sorted one
#include<iostream>
#include<stdlib.h>
using namespace std;
//         1
//    2         3
//  4     5    6      7
//8   9  A  B C  D  E   F
//floor of by 2
void printer(int *arr)
{
    if(arr[0]==0) cout<<"Empty array try inserting some data";
    else
    {
        for(int i=1;i<=arr[0];i++)
        {
            cout<<arr[i]<<"   ";
        }
    }
    cout<<endl;
}
int * insert(int *arr,int n)
{
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
int * heapify(int *arr)
{
    int index=1,temp;
    arr[1]=arr[arr[0]];
    while(index<=arr[0]&&(2*index+1)<=arr[0])//Equailty verify
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
int * heapsort(int *arr)
{
    int i,size=arr[0],temp=arr[1];
    for(i=1;i<=size;i++)
    {
        temp=arr[1];
        arr=heapify(arr);
        arr[arr[0]+1]=temp;
    }
    arr[0]=size;
    return arr;
}

int main()
{
    int n=10,i,*arr;
    arr=(int *)malloc(sizeof(int)*(n+1));
    arr[0]=0;
    int temp;
    arr=insert(arr,6);
    arr=insert(arr,5);
    arr=insert(arr,4);
    arr=heapsort(arr);
    printer(arr);
    free(arr);
    return 0;
}