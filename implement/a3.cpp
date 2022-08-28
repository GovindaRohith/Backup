// 1.Each node contains the Age of a faculty.

// 2.You should implement
// A.Insert
// B.Delete
#include<iostream>
#include<stdlib.h>
using namespace std;
int * insert_a(int *arr,int age,int n)
{   
    if(arr[n+1]==n+1)
    {
        printf("Array  full");
        return arr;
    }
    arr[arr[n+1]]=age;
    arr[n+1]++;
    return arr;
}
int * delete_b(int *arr,int n)
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
void print_func(int *arr,int n)
{
    int i;
    if(arr[n]==arr[n+1]) cout<<"Empty array!!!";
    for(i=arr[n];i<arr[n+1];i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n=100,*arr;
    arr=(int *)malloc(sizeof(int )*(n+2));
    arr[n]=0;
    arr[n+1]=0;
    arr=insert_a(arr,18,n);
    arr=insert_a(arr,15,n);
    arr=insert_a(arr,18,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    arr=delete_b(arr,n);
    print_func(arr,n);
    free(arr);
    return 0;
}