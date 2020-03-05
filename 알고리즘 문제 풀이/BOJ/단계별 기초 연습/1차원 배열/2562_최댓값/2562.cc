#include<iostream>
using namespace std;

int main()
{
    int input;
    int max=0,max_position;
    for(int i=0;i<9;i++)
    {
        cin>>input;
        if(max<input)
        {
            max=input;
            max_position=i+1;
        }
    }
    cout<<max<<endl<<max_position;
    
    return 0;
}