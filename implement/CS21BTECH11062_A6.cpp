/*
Code by
Govinda Rohith Y
CS21BTECH11062
Assignment-6 
Implementation of heap
*/
// 1.Each node contains the Age of a faculty.
//Implementation of Heap
// 2.You should implement
// A.Insert
// B.Find Min
// C.Delete Min
#include<iostream>
#include<stdlib.h>
#define INIT 10 //INIT represents (max no of elements+1)
using namespace std;
int min(int *arr)
{
    //Function to return min value of given heap arr
    if(arr[0]==0)  //Empty array case
    {
        cout<<"Empty array"<<endl;
        return -1;
    }
    if(arr!=NULL) return arr[1];
    else return -1;
}
void printer(int *arr)
{
    //Function to print elements in an array
    int i;
    if(arr[0]==0) cout<<"Empty array"<<endl; //Empty array case
    else
    {
        for(i=1;i<=arr[0];i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
int * insert(int *arr,int n)
{
    //Function to insert given age 'n'
    int index=arr[0],temp;
    if(index==INIT-1) //Case when array is full
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
int * delete_c(int *arr)
{
    //Function to delete min of all ages
    if(arr[0]==0) //Empty array case
    {
        cout<<"Empty array try to insert some elements"<<endl;
        return arr;
    }
    cout<<"*** Deleted Sucessfully ***"<<endl;
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
    arr[0]=arr[0]-1; //update size
    return arr;
}
int main()
{
    int *arr;
    arr=(int *)malloc(sizeof(int)*INIT);
    if(INIT<=1)
    {
        cout<<"Invalid Size !!!!"<<endl;
    }
    arr[0]=0;//arr[0] -->keeps track of no of ages(elements) present
    arr=insert(arr,8);
    arr=insert(arr,8);
    arr=insert(arr,48);
    printer(arr);
    cout<<"The minimum value of the BHT is "<<min(arr)<<endl;
    arr=delete_c(arr);
    arr=delete_c(arr);
    arr=delete_c(arr);
    printer(arr);
    free(arr);
    return 0;
}