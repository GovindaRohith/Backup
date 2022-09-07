// 1.Each node contains the Age of a faculty.

// 2.You should implement
// A.Insert
// B.Delete
#include<iostream>
#include<stdlib.h>
using namespace std;
void print_func(int *arr,int n)
{
    //arr[n]=front  -1 empty
    //arr[n+1]=back/rear  -1 empty
    //front denotes the starting element index
    //rear denotes the ending element index
    //clock wise
    int i;
    if(arr[n+1]==-1)
    {
        cout<<"Empty array try inserting some elements"<<endl;
    }
    else
    {
    for(i=arr[n];i<arr[n+1]&&i<=n-1;i=(i+1)%n)
    {
        cout<<arr[i]<<"  ";
        //updatind condition
    }
    cout<<arr[arr[n+1]]<<endl;
    }
}
int * insert_a(int *arr,int n,int a)
{
    //rear<front
    //arr[n+1]<arr[n]
    //front=rear+1%n
    if(((arr[n]-arr[n+1]==1)&&arr[n+1]!=-1)||(arr[n]==0&&arr[n+1]==n-1))
    {
        cout<<"Array full"<<endl;
        return arr;
    }
    else
    {
    arr[n+1]=(arr[n+1]+1)%n;
    arr[arr[n+1]]=a;
    return arr;
    }
}
int * delete_b(int *arr,int n)
{
    //rear<front
    //arr[n+1]<arr[n]
    if(arr[n+1]<=-1)
    {
        cout<<"Empty array"<<endl;
        return arr;
    }
    if(arr[n+1]==arr[n])
    {
        arr[n+1]=-1;
        return arr;
    }
    else
    {
        arr[n]=(arr[n]+1)%n;
        return arr;
    }
}
int main()
{
    int *arr,n=10;
    arr=(int *)malloc(sizeof(int)*(n+2));
    arr[n]=0;
    arr[n+1]=-1;
    arr=insert_a(arr,n,1);
    arr=insert_a(arr,n,2);
    arr=insert_a(arr,n,3);
    arr=insert_a(arr,n,4);
    arr=insert_a(arr,n,5);
    arr=insert_a(arr,n,6);
    arr=insert_a(arr,n,7);
    arr=insert_a(arr,n,8);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=insert_a(arr,n,9);
    arr=insert_a(arr,n,10);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    print_func(arr,n);
    free(arr);
    return 0;
}