#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char input[200];
	cin >> input;
	for (int i = 0; i < strlen(input); ++i)
		cout << (int)input[i] - 64 << " ";
	return 0;
}