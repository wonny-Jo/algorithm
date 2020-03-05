#include<iostream>
#include<cmath>
using namespace std;
#define M_PI 3.14159265358979323846

int main()
{
	double r;
	cin >> r;
	cout.precision(6);
	cout<<fixed << M_PI*r*r << endl << 2 * r*r<<endl;

	return 0;
}