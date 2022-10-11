#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int *arr;
    arr=(int *)malloc(sizeof(int)*2);
    arr[0]=1;
    arr[1]=2;
    if(&arr[2]==NULL) cout<<"YEp"<<endl;
    free(arr);
    return 0;
}