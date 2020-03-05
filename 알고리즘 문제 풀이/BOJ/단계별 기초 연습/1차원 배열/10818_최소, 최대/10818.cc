#include<iostream>
using namespace std;

int main()
{
    long N,a;
    cin>>N;
    long min=1000000,max=-1000000;
    
    for(int i=0;i<N;i++)
    {
        cin>>a;
        if(a>max)
            max=a;
        if(a<min)
            min=a;
    }
    cout<<min<<" "<<max;
    
    
    return 0;
}