#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	char** input = new char* [T];
	for (int i = 0; i < T; ++i)
	{
		input[i] = new char[8];
		cin >> input[i];
	}
	char year[5], month[3], day[3];
	for (int i = 0; i < T; ++i) {
		year[0] = input[i][0]; year[1] = input[i][1]; year[2] = input[i][2]; year[3] = input[i][3]; year[4] = 0;
		month[0] = input[i][4]; month[1] = input[i][5]; month[2] = 0;
		day[0] = input[i][6]; day[1] = input[i][7]; day[2] = 0;
		if (atoi(month) < 1 || atoi(month) > 12)
			cout << "#" << i + 1 << " " << -1 << endl;
		else {
			if (atoi(month) == 2)
			{
				if (atoi(day) < 1 || atoi(day) > 28)
					cout << "#" << i + 1 << " " << -1 << endl;
				else
					cout << "#" << i + 1 << " " << year << "/" << month << "/" << day << endl;
			}
			else if (atoi(month) == 4 || atoi(month) == 6 || atoi(month) == 9 || atoi(month) == 11)
			{
				if (atoi(day) < 1 || atoi(day) > 30)
					cout << "#" << i + 1 << " " << -1 << endl;
				else
					cout << "#" << i + 1 << " " << year << "/" << month << "/" << day << endl;
			}
			else
			{
				if (atoi(day) < 1 || atoi(day) > 31)
					cout << "#" << i + 1 << " " << -1 << endl;
				else
					cout << "#" << i + 1 << " " << year << "/" << month << "/" << day << endl;
			}
		}
	}
	delete input;
	return 0;
}