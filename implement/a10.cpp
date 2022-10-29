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
int n=4;//no of vertices
class Graph
{
    public:
    int **arr;
};
void free_mem(Graph r)
{
    int i,**arr=r.arr;
    for(i=0;i<n;i++)
    {
        free(arr[i]);
    }
    free(arr);
}
Graph alloter()
{
    Graph g;
    int i,**arr;
    arr=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(sizeof(int)*n);
    }
    g.arr=arr;
    return g;
}
int main()
{
    Graph r=alloter();
    
    free_mem(r);
    return 0;
}