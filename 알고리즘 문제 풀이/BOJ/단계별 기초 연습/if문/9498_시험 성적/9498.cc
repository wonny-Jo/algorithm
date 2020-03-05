#include<iostream>
using namespace std;

int main()
{
    int point;
    cin>>point;
    
    if(point>=90)
        cout<<'A';
    else if(point>=80)
        cout<<'B';
    else if(point>=70)
        cout<<'C';
    else if(point>=60)
        cout<<'D';
    else
        cout<<'F';
    
    
    return 0;
}