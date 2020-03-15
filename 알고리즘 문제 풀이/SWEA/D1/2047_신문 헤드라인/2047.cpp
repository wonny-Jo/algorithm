#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char input[200];
	cin >> input;
	for (int i = 0; i < strlen(input); ++i) {
		if (input[i] >= 97 && input[i] <= 122)
			cout << (char)(input[i] - 32);
		else
			cout << input[i];
	}
	return 0;
}