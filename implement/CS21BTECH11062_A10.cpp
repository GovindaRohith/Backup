/*
Code by Govinda Rohith Y
CS21BTECH11062
Assignment-10
Implementation of kruskal algorithm
*/
// Step 1: Sort all edges in increasing order of their edge weights.
// Step 2: Pick the smallest edge.
// Step 3: Check if the new edge creates a cycle or loop in a spanning 
// tree.
// Step 4: If it doesn’t form the cycle, then include that edge in MST. 
// Otherwise, discard it.
// Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.
// 1. Marks four. You will get either four or zero
#include<iostream>
#include<stdlib.h>
using namespace std;
int n=6;//no of vertices
class Graph
{
    //class to store Graph in terms of matrix of size n x n
    public:
    int **arr;
};
Graph alloter()
{
    //fucntion to create a graph
    Graph g;
    int i,**arr;
    arr=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
    {
        arr[i]=(int *)calloc(sizeof(int),n);
    }
    g.arr=arr;
    return g;
}
void free_mem(Graph r)
{
    //function to free allotted memory for Graph r
    int i,**arr=r.arr;
    for(i=0;i<n;i++)
    {
        free(arr[i]);
    }
    free(arr);
}
void printer(Graph g)
{
    //function to print edges with their weights and vertices
    int i,j,counter=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(g.arr[i][j]!=0)
            {            
                cout<<i<<"----"<<j<<"  Weight: "<<g.arr[i][j]<<endl;
                counter=counter+g.arr[i][j];
            }
        }
    }
    cout<<"Total weight :"<<counter<<endl;
}
int find(int *arr,int n)
{
    //Determines which subset a particular element is in
    while(arr[n]!=n)
    {
        n=arr[n];
    }
    return n;
}
int *sort(Graph g,int *arr,int size)
{
    //function to sort array according to their weights in matrix
    int i,temp;
    bool turn=false;
    for(i=0;i<size-1;i++)
    {
        if(g.arr[arr[i]/n][arr[i]%n]>g.arr[arr[i+1]/n][arr[i+1]%n])
        {
            turn=true;
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    if(turn) return sort(g,arr,size);
    return arr;
}
Graph kruskal(Graph g)
{
    //function which returns minimum spanning tree
    int i,j,*warr,counter=-1,index=0,*set,temp1,temp2;
    for(i=0;i<n;i++) //remove self loops
    {
        g.arr[i][i]=0;
    }
    warr=(int *)malloc(sizeof(int)*(n*n-n));
    for(i=0;i<n;i++)
    {
        counter=counter+i+1;
        for(j=i+1;j<n;j++)
        {
            counter++;
            if(g.arr[i][j]!=0)
            {
                warr[index]=counter;
                index++;
            }
        }
    }
    warr=sort(g,warr,index);
    set=(int *)malloc(sizeof(int)*(n)); 
    for(i=0;i<n;i++)
    {
        set[i]=i;
    }
    for(i=0;i<index;i++)
    {
        temp1=find(set,warr[i]/n);
        temp2=find(set,warr[i]%n);
        if(temp1==temp2) 
        {
            //loop is present
            g.arr[warr[i]/n][warr[i]%n]=0;
            g.arr[warr[i]%n][warr[i]/n]=0;
        }
        else
        {
            //loop is not present
            set[temp1]=set[temp2];
        }
    }
    free(warr);
    free(set);
    return g;
}
Graph insert(Graph g,int start,int destiny,int weight)
{
    //function to insert edge between start and destiny node with given weight
    if(start>=n||destiny>=n)
    {
        cout<<"Entered vertices are exceeding max number of vertices"<<endl;
        return g;
    }
    if(g.arr[start][destiny]==0||weight<=g.arr[start][destiny])
    {
        g.arr[start][destiny]=weight;
        g.arr[destiny][start]=weight;
    } 
    cout<<"*** Edge added successfully ***"<<endl;
    return g;
}
int main()
{
    //NOTE number of vertices are allotted as global varibale upside
    Graph g=alloter();
    g=insert(g,0,1,10);
    g=insert(g,0,1,5);
    g=insert(g,0,4,3);
    g=insert(g,0,5,7);
    g=insert(g,1,2,4);
    g=insert(g,1,3,2);
    g=insert(g,1,4,6);
    g=insert(g,3,2,2);
    g=insert(g,3,4,3);
    g=insert(g,5,4,8);
    g=kruskal(g);
    printer(g);
    free_mem(g);
    return 0;
}