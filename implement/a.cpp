#include<iostream>
using namespace std;
//first one -1
//second one 1
int lexicon(string str1,string str2)
{
    int len,i;
    if(str1.length()>str2.length()) len=str2.length();
    else  len=str1.length();
    for(i=0;i<len;i++)
    {
        if((int)str1[i]<(int)str2[i])
        {
            return -1;
        }
    }
    return 1;
}
int main()
{
    string str1,str2;
    cout<<"Enter any two wtrings"<<endl;
    cin>>str1;
    cin>>str2;
    cout<<lexicon(str1,str2)<<endl;
    return 0;
}