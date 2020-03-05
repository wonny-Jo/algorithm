#include<iostream>
using namespace std;

int main()
{
    int A,B;
    while(true)
    {
        cin>>A>>B;
        if(A<=10&&A>=0&&B<=10&&B>=0)
            break;
        else
            cout<<"다시 입력하세요"<<endl;
    }
    cout<<A-B;
    return 0;
}