//Code by
//Govinda Rohith Y
//CS21BTECH11062
//Assignment-7
//Implementation of heap sort
// 1.Each node contains the Age of a faculty.
// 2.You should implement take input an array and print sorted one
#include<iostream>
#include<stdlib.h>
#define INIT 3 //INIT represents max no of elements in an array
using namespace std;
void printer(int *arr)
{
    //Function to print elements in given heap 
    if(arr[0]==0) cout<<"Empty array try inserting some data";
    else
    {
        for(int i=1;i<=arr[0];i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

int * insert(int *arr,int n)
{
    //Function to insert given age 'n'
    int index=arr[0],temp;
    if(index==INIT) //Case when array is full
    {
        cout<<"Array full !!!"<<endl;
        return arr;
    }
    cout<<"*** Inserted Sucessfully ***"<<endl;
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
    arr[0]++; //update size
    return arr;
}
int * heapify(int *arr)
{
    //function to heapify the tree obtained after deleting the min value
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
    //Heapsort function to sort HEAP ARRAY 'arr'
    int i,size=arr[0],temp=arr[1];
    for(i=1;i<size;i++) //loop just checks if the array is sorted
    {
        if(arr[i]<arr[i+1])
        {
            break;
        }
    }
    if(i==size) return arr;
    for(i=1;i<=size;i++)
    {
        temp=arr[1];
        arr=heapify(arr);
        arr[arr[0]+1]=temp;
    }
    arr[0]=size;
    return arr;
}
int * convert_sort(int *arr)
{
    //Function to convert regular array to normal min heap and sort
    //NOTE array should be only size INIT
    int i,*arr2;
    arr2=(int *)malloc(sizeof(int)*(INIT+1));
    arr2[0]=0;
    for(i=0;i<INIT;i++)
    {
        arr2=insert(arr2,arr[i]);
    }
    arr2=heapsort(arr2);
    for(i=0;i<INIT;i++)
    {
        arr[i]=arr2[i+1];
    }
    free(arr2);
    return arr;
}
void print_norm(int *arr)
{
    //Function to print NORMAL array 'arr' NOT min heap array
    for(int i=0;i<INIT;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int *arr;
    arr=(int *)malloc(sizeof(int)*(INIT+1));
    arr[0]=0;//arr[0] -->keeps track of no of ages(elements) present
    if(INIT<=0) 
    {
        cout<<"Invalid size"<<endl;
        return 0;
    }
    arr=insert(arr,5);
    arr=insert(arr,1);
    arr=insert(arr,2);
    arr=heapsort(arr);
    printer(arr);
    free(arr);
    return 0;
}