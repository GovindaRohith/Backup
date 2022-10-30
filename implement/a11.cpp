#include<iostream>
using namespace std;
int main()
{
    int counter=0;
    while(counter<5)
    {
        cout<<rand()%2<<endl;
        counter++;
    }
    return 0;
}