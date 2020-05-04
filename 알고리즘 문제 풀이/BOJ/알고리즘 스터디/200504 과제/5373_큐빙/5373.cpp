#include<iostream>
#include<string.h>
using namespace std;
char cube[6][3][3] = { 
{{'w','w','w'},{'w','w','w'},{'w','w','w'}}, //À§
{{'g','g','g'},{'g','g','g'},{'g','g','g'}}, //¿Þ
{{'r','r','r'},{'r','r','r'},{'r','r','r'}}, //¾Õ
{{'b','b','b'},{'b','b','b'},{'b','b','b'}}, //¿À
{{'o','o','o'},{'o','o','o'},{'o','o','o'}}, //µÚ
{{'y','y','y'},{'y','y','y'},{'y','y','y'}}  //¹Ø
};
char temp[6][3][3];

void rotate(int n, bool isRight)
{
	char rotated[3][3];
	if (!isRight)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				rotated[i][j] = temp[n][j][2 - i];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[n][i][j] = rotated[i][j];
	}
	else
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				rotated[i][j] = temp[n][2 - j][i];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[n][i][j] = rotated[i][j];
	}
}

void rotation(string command)
{
	if (command == "U-")//1234
	{
		char a[3] = { temp[4][0][0],temp[4][0][1] ,temp[4][0][2] };
		temp[4][0][0] = temp[3][0][0]; temp[4][0][1] = temp[3][0][1]; temp[4][0][2] = temp[3][0][2];
		temp[3][0][0] = temp[2][0][0]; temp[3][0][1] = temp[2][0][1]; temp[3][0][2] = temp[2][0][2];
		temp[2][0][0] = temp[1][0][0]; temp[2][0][1] = temp[1][0][1]; temp[2][0][2] = temp[1][0][2];
		temp[1][0][0] = a[0]; temp[1][0][1] =a[1]; temp[1][0][2] = a[2];
		rotate(0, 0);
	}
	else if (command == "U+")//1432
	{
		char a[3] = { temp[1][0][0],temp[1][0][1] ,temp[1][0][2] };
		temp[1][0][0] = temp[2][0][0]; temp[1][0][1] = temp[2][0][1]; temp[1][0][2] = temp[2][0][2];
		temp[2][0][0] = temp[3][0][0]; temp[2][0][1] = temp[3][0][1]; temp[2][0][2] = temp[3][0][2];
		temp[3][0][0] = temp[4][0][0]; temp[3][0][1] = temp[4][0][1]; temp[3][0][2] = temp[4][0][2];
		temp[4][0][0] = a[0]; temp[4][0][1] = a[1]; temp[4][0][2] = a[2];
		rotate(0, 1);
	}
	else if (command == "D-")//1432
	{
		char a[3] = { temp[1][2][0],temp[1][2][1] ,temp[1][2][2] };
		temp[1][2][0] = temp[2][2][0]; temp[1][2][1] = temp[2][2][1]; temp[1][2][2] = temp[2][2][2];
		temp[2][2][0] = temp[3][2][0]; temp[2][2][1] = temp[3][2][1]; temp[2][2][2] = temp[3][2][2];
		temp[3][2][0] = temp[4][2][0]; temp[3][2][1] = temp[4][2][1]; temp[3][2][2] = temp[4][2][2];
		temp[4][2][0] = a[0]; temp[4][2][1] = a[1]; temp[4][2][2] = a[2];
		rotate(5, 0);
	}
	else if (command == "D+")//1234
	{
		char a[3] = { temp[4][2][0],temp[4][2][1] ,temp[4][2][2] };
		temp[4][2][0] = temp[3][2][0]; temp[4][2][1] = temp[3][2][1]; temp[4][2][2] = temp[3][2][2];
		temp[3][2][0] = temp[2][2][0]; temp[3][2][1] = temp[2][2][1]; temp[3][2][2] = temp[2][2][2];
		temp[2][2][0] = temp[1][2][0]; temp[2][2][1] = temp[1][2][1]; temp[2][2][2] = temp[1][2][2];
		temp[1][2][0] = a[0]; temp[1][2][1] = a[1]; temp[1][2][2] = a[2];
		rotate(5, 1);
	}
	else if (command == "F-")//0153
	{
		char a[3] = { temp[0][2][0],temp[0][2][1] ,temp[0][2][2] };
		temp[0][2][0] = temp[3][0][0]; temp[0][2][1] = temp[3][1][0]; temp[0][2][2] = temp[3][2][0];
		temp[3][0][0] = temp[5][0][2]; temp[3][1][0] = temp[5][0][1]; temp[3][2][0] = temp[5][0][0];
		temp[5][0][0] = temp[1][0][2]; temp[5][0][1] = temp[1][1][2]; temp[5][0][2] = temp[1][2][2];
		temp[1][0][2] = a[2]; temp[1][1][2] = a[1]; temp[1][2][2] = a[0];
		rotate(2, 0);
	}
	else if (command == "F+")//0351
	{
		char a[3] = { temp[0][2][0],temp[0][2][1] ,temp[0][2][2] };
		temp[0][2][0] = temp[1][2][2]; temp[0][2][1] = temp[1][1][2]; temp[0][2][2] = temp[1][0][2];
		temp[1][0][2] = temp[5][0][0]; temp[1][1][2] = temp[5][0][1]; temp[1][2][2] = temp[5][0][2];
		temp[5][0][2] = temp[3][0][0]; temp[5][0][1] = temp[3][1][0]; temp[5][0][0] = temp[3][2][0];
		temp[3][0][0] = a[0]; temp[3][1][0] = a[1]; temp[3][2][0] = a[2];
		rotate(2, 1);
	}
	else if (command == "B-")//0351
	{
		char a[3] = { temp[0][0][2],temp[0][0][1],temp[0][0][0] };
		temp[0][0][2] = temp[1][0][0]; temp[0][0][1] = temp[1][1][0]; temp[0][0][0] = temp[1][2][0];
		temp[1][0][0] = temp[5][2][0]; temp[1][1][0] = temp[5][2][1]; temp[1][2][0] = temp[5][2][2];
		temp[5][2][0] = temp[3][2][2]; temp[5][2][1] = temp[3][1][2]; temp[5][2][2] = temp[3][0][2];
		temp[3][0][2] = a[2]; temp[3][1][2] = a[1]; temp[3][2][2] = a[0];
		rotate(4, 0);
	}
	else if (command == "B+")//0153
	{
		char a[3] = { temp[0][0][2],temp[0][0][1],temp[0][0][0] };
		temp[0][0][2] = temp[3][2][2]; temp[0][0][1] = temp[3][1][2]; temp[0][0][0] = temp[3][0][2];
		temp[3][2][2] = temp[5][2][0]; temp[3][1][2] = temp[5][2][1]; temp[3][0][2] = temp[5][2][2];
		temp[5][2][0] = temp[1][0][0]; temp[5][2][1] = temp[1][1][0]; temp[5][2][2] = temp[1][2][0];
		temp[1][0][0] = a[0]; temp[1][1][0] = a[1]; temp[1][2][0] = a[2];
		rotate(4, 1);
	}
	else if (command == "L-")//0452
	{
		char a[3] = { temp[0][0][0],temp[0][1][0] ,temp[0][2][0] };
		temp[0][0][0] = temp[2][0][0]; temp[0][1][0] = temp[2][1][0]; temp[0][2][0] = temp[2][2][0];
		temp[2][0][0] = temp[5][0][0]; temp[2][1][0] = temp[5][1][0]; temp[2][2][0] = temp[5][2][0];
		temp[5][0][0] = temp[4][2][2]; temp[5][1][0] = temp[4][1][2]; temp[5][2][0] = temp[4][0][2];
		temp[4][2][2] = a[0]; temp[4][1][2] = a[1]; temp[4][0][2] = a[2];
		rotate(1, 0);
	}
	else if (command == "L+")//0254
	{
		char a[3] = { temp[0][0][0],temp[0][1][0] ,temp[0][2][0] };
		temp[0][0][0] = temp[4][2][2]; temp[0][1][0] = temp[4][1][2]; temp[0][2][0] = temp[4][0][2];
		temp[4][2][2] = temp[5][0][0]; temp[4][1][2] = temp[5][1][0]; temp[4][0][2] = temp[5][2][0];
		temp[5][0][0] = temp[2][0][0];  temp[5][1][0] = temp[2][1][0];temp[5][2][0] = temp[2][2][0];
		temp[2][0][0] = a[0]; temp[2][1][0] = a[1]; temp[2][2][0] = a[2];
		rotate(1, 1);
	}
	else if (command == "R-")//0254
	{
		char a[3] = { temp[0][0][2],temp[0][1][2] ,temp[0][2][2] };
		temp[0][0][2] = temp[4][2][0]; temp[0][1][2] = temp[4][1][0]; temp[0][2][2] = temp[4][0][0];
		temp[4][2][0] = temp[5][0][2]; temp[4][1][0] = temp[5][1][2]; temp[4][0][0] = temp[5][2][2];
		temp[5][0][2] = temp[2][0][2]; temp[5][1][2] = temp[2][1][2]; temp[5][2][2] = temp[2][2][2];
		temp[2][0][2] = a[0]; temp[2][1][2] = a[1]; temp[2][2][2] = a[2];
		rotate(3, 0);
	}
	else if (command == "R+")//0452
	{
		char a[3] = { temp[0][0][2],temp[0][1][2] ,temp[0][2][2] };
		temp[0][0][2] = temp[2][0][2]; temp[0][1][2] = temp[2][1][2]; temp[0][2][2] = temp[2][2][2];
		temp[2][0][2] = temp[5][0][2]; temp[2][1][2] = temp[5][1][2]; temp[2][2][2] = temp[5][2][2];
		temp[5][0][2] = temp[4][2][0]; temp[5][1][2] = temp[4][1][0]; temp[5][2][2] = temp[4][0][0];
		temp[4][2][0] = a[0]; temp[4][1][0] = a[1]; temp[4][0][0] = a[2];
		rotate(3, 1);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int t; cin >> t;
	for (int a = 0; a < t; a++)
	{
		int n; cin >> n;
		string command; 
		memcpy(temp, cube, sizeof(temp));
		for (int i = 0; i < n; i++)
		{
			cin >> command;
			rotation(command);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << temp[0][i][j];
			cout << '\n';
		}
	}

	return 0;
}
