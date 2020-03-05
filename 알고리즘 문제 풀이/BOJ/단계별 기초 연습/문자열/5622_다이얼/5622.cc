#include<iostream>
using namespace std;

int _strlen(char* str)
{
	int count = 0;
	for (int i = 0; str[i]; ++i)
		++count;
	return count;
}

int main()
{
	char* input = new char[15];
	cin >> input;
	int size = _strlen(input);
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		if ('A' <= input[i] && input[i] <= 'C')
			sum += 3;
		else if ('D' <= input[i] && input[i] <= 'F')
			sum += 4;
		else if ('G' <= input[i] && input[i] <= 'I')
			sum += 5;
		else if ('J' <= input[i] && input[i] <= 'L')
			sum += 6;
		else if ('M' <= input[i] && input[i] <= 'O')
			sum += 7;
		else if ('P' <= input[i] && input[i] <= 'S')
			sum += 8;
		else if ('T' <= input[i] && input[i] <= 'V')
			sum += 9;
		else if ('W' <= input[i] && input[i] <= 'Z')
			sum += 10;
		else
			sum += 11;
	}
	cout << sum;
	delete input;
	return 0;
}
