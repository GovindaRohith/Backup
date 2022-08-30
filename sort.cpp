#include<iostream>
#include<stdlib.h>
using namespace std;
//         1
//    2         3
//  4     5    6      7
//8   9  A  B C  D  E   F
//floor of by 2
int * heapify(int * arr,int index)
{
    int temp;
    if(2*index<=arr[0]&&2*index+1<=arr[0])
    {   
        if(arr[index]>=arr[2*index]&&arr[index]>=arr[2*index+1])
        {
            return arr;
        }
        else
        {
            if(arr[2*index+1]>=arr[2*index])
            {
                temp=arr[index];
                arr[index]=arr[2*index+1];
                arr[2*index+1]=temp;
                return heapify(arr,2*index+1);
            }
            else
            {
                temp=arr[index];
                arr[index]=arr[2*index];
                arr[2*index]=temp;
                return heapify(arr,2*index);
            }
        }
    }
    return arr;
}
// last non leaf node --> floor(n/2)
int * heapsort(int *arr)
{
    int i,last=arr[0]/2;
    for(i=last;i>=1;i=i-1)
    {
        arr=heapify(arr,i);
    }
    return arr;
}
int * insert(int * arr,int n)
{
    arr[0]++;
    arr[arr[0]]=n;
    return arr;
}
void printer(int *arr)
{
    for(int i=1;i<=arr[0];i++)
    {
        cout<<arr[i]<<"   "<<endl;
    }
}
int main()
{
    int n,i,*arr;
    cout<<"Enter the size of arr"<<endl;;
    cin>>n;
    arr=(int *)malloc(sizeof(int)*(n+1));
    arr[0]=0;
    int temp;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        arr=insert(arr,temp);
    }
    arr=heapsort(arr);
    printer(arr);
    //size arr[0]
    free(arr);
    return 0;
}