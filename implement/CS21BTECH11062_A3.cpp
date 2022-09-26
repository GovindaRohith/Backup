/*
Code by
Govinda Rohith Y
CS21BTECH11062
Assignment 3
Implementation of circular queue using array
*/
// 1.Each node contains the Age of a faculty.
// 2.You should implement
// A.enq
// B.deq
#include<iostream>
#include<stdlib.h>
using namespace std;
void print_func(int *arr,int n)
{
    //This function prints array elements from front index(arr[n])
    //to rear index(arr[n+1]) in clock wise direction
    int i;
    if(arr[n+1]==-1)
    {
        //Empty queue case
        cout<<"Empty array try enqueuing some elements"<<endl;
    }
    else
    {
    for(i=arr[n];i!=arr[n+1]&&i<=n-1;i=(i+1)%n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[arr[n+1]]<<endl;
    }
}
int * enq_a(int *arr,int n,int a)
{
    //function to enqueue a certain given element
    if(((arr[n]-arr[n+1]==1)&&arr[n+1]!=-1)||(arr[n]==0&&arr[n+1]==n-1))
    {
        //Empty queue case
        cout<<"Array full"<<endl;
        return arr;
    }
    else
    {
    arr[n+1]=(arr[n+1]+1)%n;
    arr[arr[n+1]]=a;
    cout<<"*** Enqueued Successfully ***"<<endl;
    return arr;
    }
}
int deq_b(int *arr,int n)
{
    //function to return and  dequeue element
    int temp=arr[arr[n]];
    if(arr[n+1]<=-1)
    {
        //Empty queue case
        cout<<"Empty array"<<endl;
        return -1;
    }
    if(arr[n+1]==arr[n])
    {
        //when only one entry is available
        arr[n+1]=-1;
    }
    else
    {
        arr[n]=(arr[n]+1)%n;
    }
    return temp;
}
int main()
{
    int *arr,n=10;
    //n denotes size here
    //arr defines circular queue 
    //arr[n](front)= denotes starting element index
    //arr[n+1](back/rear)= denotes the ending element index
    //arr[n+1]=-1  ==> Empty queue
    if(n<=0)
    {
        cout<<"Invalid size"<<endl;
        return 0;
    }
    arr=(int *)malloc(sizeof(int)*(n+2));
    arr[n]=0;
    arr[n+1]=-1;
    arr=enq_a(arr,n,1);
    arr=enq_a(arr,n,2);
    arr=enq_a(arr,n,3);
    arr=enq_a(arr,n,4);
    arr=enq_a(arr,n,5);
    arr=enq_a(arr,n,6);
    arr=enq_a(arr,n,7);
    arr=enq_a(arr,n,8);
    arr=enq_a(arr,n,9);
    arr=enq_a(arr,n,10); 
    cout<<"Dequeued element : "<<deq_b(arr,n)<<endl;
    print_func(arr,n);
    free(arr);
    return 0;
}