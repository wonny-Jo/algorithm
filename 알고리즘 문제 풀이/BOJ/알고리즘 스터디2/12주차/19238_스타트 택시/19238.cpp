#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <map> 
using namespace std; 
int moveDir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } }; 
int N, M, gas;
int road[21][21];
map<pair<int, int>, pair<int, int>> start2Destination;
typedef struct 
{ 
	int y, x; 
	int gas; 
}State; 

bool operator <(State a, State b) 
{ 
	if (a.gas < b.gas || (a.gas == b.gas && (a.y > b.y || ((a.y == b.y && a.x > b.x)))))
		return true;
	return false; 
} 

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

bool func(pair<int, int> start) 
{ 
	pair<int, int> destination = start2Destination[start]; 
	queue<pair<State, int>> q; 
	q.push({ { start.first, start.second, gas }, 0 }); 
	bool visited[21][21] = { 0 };
	visited[start.first][start.second] = true; 
	while (!q.empty()) 
	{ 
		int y = q.front().first.y; 
		int x = q.front().first.x; 
		int curGas = q.front().first.gas; 
		int cnt = q.front().second; q.pop(); 
		if (curGas == -1) 
			return false; 
		if (y == destination.first && x == destination.second) 
		{ 
			gas = curGas + cnt * 2; 
			return true; 
		} 
		for (int k = 0; k < 4; k++) 
		{ 
			int nextY = y + moveDir[k][0]; 
			int nextX = x + moveDir[k][1]; 
			if (!isRange(nextY, nextX) || (visited[nextY][nextX] || road[nextY][nextX]))
				continue;
			visited[nextY][nextX] = true; 
			q.push({ { nextY, nextX, curGas - 1 }, cnt + 1 });
		} 
	} 
	return false; 
} 

int main() 
{ 
	cin.sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> gas; 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> road[i][j]; 
	pair<int, int> start; 
	cin >> start.first >> start.second; 
	start.first--, start.second--; 
	for (int i = 0; i < M; i++) 
	{ 
		int y, x, y2, x2; 
		cin >> y >> x >> y2 >> x2; 
		start2Destination[{y - 1, x - 1}] = { y2 - 1,x2 - 1 }; 
	} 
	while (1) 
	{ 
		priority_queue<State> pq; 
		pq.push({ start.first, start.second, gas }); 
		bool visited[21][21] = { 0 };
		visited[start.first][start.second] = true; 
		bool flag = false; 
		while (!pq.empty()) 
		{ 
			int y = pq.top().y; 
			int x = pq.top().x; 
			int curGas = pq.top().gas; 
			pq.pop(); 
			if (curGas == -1) 
				break; 
			if (start2Destination.count({ y, x }) && start2Destination[{y, x}].first != -1) 
			{ 
				start = { y, x }; 
				flag = true; 
				gas = curGas; 
				break; 
			} 
			for (int k = 0; k < 4; k++) 
			{ 
				int nextY = y + moveDir[k][0]; 
				int nextX = x + moveDir[k][1]; 
				if (!isRange(nextY, nextX) || (visited[nextY][nextX] || road[nextY][nextX]))
					continue;
				visited[nextY][nextX] = true; 
				pq.push({ nextY, nextX, curGas - 1 }); 
			} 
		} 
		if (flag == false|| func(start) == false)
		{ 
			cout << -1 << "\n"; 
			return 0; 
		} 
		if (--M == 0) 
		{ 
			cout << gas << "\n"; 
			return 0; 
		} 
		pair<int, int> temp = start; 
		start = start2Destination[{start.first, start.second}]; 
		start2Destination[{temp.first, temp.second}] = { -1, -1 }; 
	} 
	return 0;
}